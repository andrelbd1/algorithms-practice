#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "algorithms.h"

complex
complex_mul(complex a, complex b)
{
   complex ans;
   ans.r = a.r * b.r - a.i * b.i;
   ans.i = a.r * b.i + a.i * b.r;
   return ans;
}

complex
complex_add(complex a, complex b)
{
   complex ans;

   ans.r = a.r + b.r;
   ans.i = a.i + b.i;

   return ans;
}

complex
complex_sub(complex a, complex b)
{
   complex ans;

   ans.r = a.r - b.r;
   ans.i = a.i - b.i;

   return ans;
}

void
fast_fourier_transform(complex *a, complex *y, int n, int inv)
{
   complex w, wn, twiddle;
   complex *a0;
   complex *a1;
   complex *y0;
   complex *y1;
   int i, k;

   /* Base Case */
   if (n == 1)
   {
      y[0] = a[0];
      return;
   }

   /* Calculate principal nth root of unity (i.e. exp(2*PI*i/n)) */
   if (inv)
   {
      wn.r = cos(-2*M_PI/(double)n);
      wn.i = sin(-2*M_PI/(double)n);
   }
   else
   {
      wn.r = cos(2*M_PI/(double)n);
      wn.i = sin(2*M_PI/(double)n);
   }
   w.r = 1.0;
   w.i = 0.0;

   /* allocate memory for even/odd coefficients and corresponding FFTs */
   a0 = (complex *) malloc((n/2) * sizeof(complex));
   a1 = (complex *) malloc((n/2) * sizeof(complex));
   y0 = (complex *) malloc((n/2) * sizeof(complex));
   y1 = (complex *) malloc((n/2) * sizeof(complex));

   /* Extract even and odd coefficients */
   for (i = 0; i < (n/2); i++)
   {
      a0[i] = a[2*i];
      a1[i] = a[2*i+1];
   }

   /* Calculate 2 FFTs of size n/2 */
   fast_fourier_transform(a0, y0, n/2, inv);
   fast_fourier_transform(a1, y1, n/2, inv);

   /* Combine results from half-size FFTs */
   for (k = 0; k < (n/2); k++)
   {
      twiddle  = complex_mul(w, y1[k]);
      y[k]     = complex_add(y0[k], twiddle);
      y[k+n/2] = complex_sub(y0[k], twiddle);

      w = complex_mul(w, wn);
   }

   free(a0);
   free(a1);
   free(y0);
   free(y1);

   return;
}

int
*multiply_trivial(int P[], int Q[], int n)
{
    int result_size = 2*n + 1;
    int *result = (int *) calloc(result_size, sizeof(int));

    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < n + 1; j++)
            result[i+j] += P[i] * Q[j];

    return result;
}

int
*multiply_divide_conquer(int P[], int Q[], int n)
{
    int result_size = 2*n + 1;
    int *result = (int *) calloc(result_size, sizeof(int));

    // Base case
    if (n == 1)
    {
        result[0] = P[0] * Q[0];
        return result;
    }

    // Divide
    int d = n / 2;
    if (n % 2 == 1)
        d++;

    int *pHigh = (int *) calloc(d, sizeof(int));
    int *qHigh = (int *) calloc(d, sizeof(int));
    int *pLow  = (int *) calloc(d-n%2, sizeof(int));
    int *qLow  = (int *) calloc(d-n%2, sizeof(int));

    for (int i = 0; i < d; i++)
    {
        pHigh[i] = P[i+d];
        qHigh[i] = Q[i+d];

        pLow[i] = P[i];
        qLow[i] = Q[i];
    }

    int *auxP = (int *) calloc(d, sizeof(int));
    int *auxQ = (int *) calloc(d, sizeof(int));

    for(int i = 0; i < d; i++)
    {
        auxP[i] = pLow[i]+pHigh[i];
        auxQ[i] = qLow[i]+qHigh[i];
    }

    // Conquer
    int *lowPQ  = multiply_divide_conquer(pLow,qLow,d);
    int *middle = multiply_divide_conquer(auxP, auxQ, d);
    int *highPQ = multiply_divide_conquer(pHigh,qHigh,d);

    // Combine
    for (int i = 0; i < n; i++)
    {
        result[i]     += lowPQ[i];
        result[i+d]   += middle[i]  - lowPQ[i] - highPQ[i];
        result[i+2*d] += highPQ[i];
    }

    free(pHigh); free(qHigh); free(pLow); free(qLow);
    free(lowPQ); free(middle); free(highPQ);

    return result;
}

int
*multiply_fft(int P[], int Q[], int n)
{
    int i, j;

    /* Allocate space for result */
    int result_size = 2*n + 1;
    int *result = (int *) calloc(result_size, sizeof(int));

    /* Determine the next biggest power of two */
    int next_power_of_2 = 1;
    while (next_power_of_2 < n)
        next_power_of_2 <<= 1;

    /* Allocate space for aux polynomials */
    complex *a = (complex *)malloc(2 * next_power_of_2 * sizeof(complex));
    complex *b = (complex *)malloc(2 * next_power_of_2 * sizeof(complex));

    /* Read coefficients from stdin */
    for (i = 0; i < n; i++)
    {
        a[i].r = (double) P[i];
        a[i].i = 0.0;
        b[i].r = (double) Q[i];
        b[i].i = 0.0;
    }

    /* Pad the rest with zeros */
    for (i = n; i < (2 * next_power_of_2); i++)
    {
        a[i].r = 0.0; a[i].i = 0.0;
        b[i].r = 0.0; b[i].i = 0.0;
    }

    n = next_power_of_2;

    /* Multiply polynomials */
    complex *ya;
    complex *yb;

    n = 2 * n;
    /* Allocate storage for fft results */
    ya = (complex *)malloc(n * sizeof(complex));
    yb = (complex *)malloc(n * sizeof(complex));

    /* DFT of A and B */
    fast_fourier_transform(a, ya, n, 0);
    fast_fourier_transform(b, yb, n, 0);

    /* Pointwise Multiplication */
    for (j = 0; j < n; j++)
        ya[j] = complex_mul(ya[j], yb[j]);

    /* Inverse DFT (swapped input and output arrays) */
    fast_fourier_transform(ya, a, n, 1);

    /* Divide real part by n */
    for (j = 0; j < (n-1); j++)
    {
        a[j].r = a[j].r/n;
        if (j < result_size)
            result[j] = (int) round(a[j].r);
    }

    free(ya);
    free(yb);
    free(a);
    free(b);

    return result;
}

int
read_input(char *filename, int **p, int **q)
{
    int n;
    FILE *file = fopen(filename, "r");

    if (file)
    {
        fscanf(file, "%d", &n);

        *p = (int *) malloc((n + 1) * sizeof(int));
        for (int i = 0; i < n + 1; i++)
            fscanf(file, "%d", *p+i);

        *q = (int *) malloc((n + 1) * sizeof(int));
        for (int i = 0; i < n + 1; i++)
            fscanf(file, "%d", *q+i);

        fclose(file);
    }

    return n;
}