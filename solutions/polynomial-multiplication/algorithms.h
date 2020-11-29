typedef struct
{
   double r; /* real */
   double i; /* imaginary */
} complex;

complex complex_mul(complex, complex);
complex complex_add(complex, complex);
complex complex_sub(complex, complex);
void fast_fourier_transform(complex*, complex*, int, int);

int* multiply_trivial(int[], int[], int);
int* multiply_divide_conquer(int[], int[], int);
int* multiply_fft(int[], int[], int);

int read_input(char*, int**, int**);