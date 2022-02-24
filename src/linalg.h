#ifndef LINALG
#define LINALG

#include <stdio.h>
#include <stdlib.h>

extern const double vector_add(const double x[], const double y[]);
extern const double vector_sub(const double x[], const double y[]);
extern const double vector_scalar_mult(const double x[], const double y[]);
extern double dot_prod(const double x[], const double y[]);
extern void matadd(double a[][], double b[][]);
extern void matmul(double a[][], double b[][])

#endif