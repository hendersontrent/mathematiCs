#ifndef LINALG
#define LINALG

#include <stdio.h>
#include <stdlib.h>

extern const double vector_add(const double x[], const double y[]);
extern const double vector_sub(const double x[], const double y[]);
extern const double vector_scalar_mult(const double x[], const double y[]);
extern double dot_prod(const double x[], const double y[]);

#endif