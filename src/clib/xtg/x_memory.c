#include "libxtg_.h"
#include "logger.h"

/* Run free() on an arbitrary list of single pointers */

void
x_free(int num, ...)
{

    int i;
    va_list valist;

    va_start(valist, num);

    for (i = 0; i < num; i++) {
        free(va_arg(valist, void *));
        logger_info(LI, FI, FU, "Freeing pointer %d of %d", i + 1, num);
    }

    va_end(valist);
}

/* allocate double 2D pointers to be contiguous in memory */

double **
x_allocate_2d_double(int n1, int n2)
{
    int i;

    double *data = malloc(sizeof(double) * n1 * n2);

    double **ptr_array = malloc(sizeof(double *) * n1);
    for (i = 0; i < n1; i++) {
        ptr_array[i] = data + (i * n2);
    }
    return ptr_array;
}

void
x_free_2d_double(double **ptr_array)
{
    if (!ptr_array)
        return;
    if (ptr_array[0])
        free(ptr_array[0]);
    free(ptr_array);
}

float **
x_allocate_2d_float(int n1, int n2)
{
    int i;

    float *data = malloc(sizeof(float) * n1 * n2);

    float **ptr_array = malloc(sizeof(float *) * n1);
    for (i = 0; i < n1; i++) {
        ptr_array[i] = data + (i * n2);
    }
    return ptr_array;
}

void
x_free_2d_float(float **ptr_array)
{
    if (!ptr_array)
        return;
    if (ptr_array[0])
        free(ptr_array[0]);
    free(ptr_array);
}

int **
x_allocate_2d_int(int n1, int n2)
{
    int i;

    int *data = malloc(sizeof(int) * n1 * n2);

    int **ptr_array = malloc(sizeof(int *) * n1);
    for (i = 0; i < n1; i++) {
        ptr_array[i] = data + (i * n2);
    }
    return ptr_array;
}

void
x_free_2d_int(int **ptr_array)
{
    if (!ptr_array)
        return;
    if (ptr_array[0])
        free(ptr_array[0]);
    free(ptr_array);
}

mbool **
x_allocate_2d_mbool(int n1, int n2)
{
    int i;

    mbool *data = malloc(sizeof(mbool) * n1 * n2);

    mbool **ptr_array = malloc(sizeof(mbool *) * n1);
    for (i = 0; i < n1; i++) {
        ptr_array[i] = data + (i * n2);
    }
    return ptr_array;
}

void
x_free_2d_mbool(mbool **ptr_array)
{
    if (!ptr_array)
        return;
    if (ptr_array[0])
        free(ptr_array[0]);
    free(ptr_array);
}
