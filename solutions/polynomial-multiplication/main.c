#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "algorithms.h"
#include "CPUTimer.h"
static CPUTimer totaltime_;

int
main(int argc, char **argv)
{
    if (argc == 1)
    {
        printf ("No input\n");
        return 0;
    }

    char *filename = argv[1];
    if (!filename)
    {
        printf ("Error to open the file input\n");
        return 0;
    }

    int *p = NULL, *q = NULL, *result = NULL;
    int n = read_input(filename, &p, &q);

    totaltime_.reset();
    totaltime_.start();
    result = multiply_trivial(p, q, n + 1);
    totaltime_.stop();
    printf("Trivial\nResult: %d\nTime: %lf seconds\n\n", *result, totaltime_.getCPUTotalSecs());
    free(result);

    totaltime_.reset();
    totaltime_.start();
    result = multiply_divide_conquer(p, q, n + 1);
    totaltime_.stop();
    printf("Divide-n-Conquer\nResult: %d\nTime: %lf seconds\n\n", *result, totaltime_.getCPUTotalSecs());
    free(result);

    totaltime_.reset();
    totaltime_.start();
    result = multiply_fft(p, q, n + 1);
    totaltime_.stop();
    printf("Fast Fourier Transform\nResult: %d\nTime: %lf seconds\n\n", *result, totaltime_.getCPUTotalSecs());
    free(result);

    free(p);
    free(q);

    return 1;
}
