#include <stdio.h>
#include <stdlib.h>

//-------------------------------
// Define basic vector operations
//-------------------------------

// Vector addition

const double vector_add(const double x[], const double y[]){

    int n = x.size();
    const double z[n];

    for(int i = 0; i < n; i++){
        z[i] = x[i] + y[i];
    }
    return z;
}

// Vector subtraction

const double vector_add(const double x[], const double y[]){

    int n = x.size();
    const double z[n];

    for(int i = 0; i < n; i++){
        z[i] = x[i] - y[i];
    }
    return z;
}

// Vector scalar multiplication

const double vector_scalar_mult(const double x[], double a){

    int n = x.size();
    const double z[n];

    for(int i = 0; i < n; i++){
        z[i] = x[i] * a;
    }
    return z;
}

// Dot product

double dot_prod(const double x[], const double y[]){

    int n = x.size();
    double dp = 0.0;

    for(int i = 0; i < n; i++){
        dp += x[i] * y[i];
    }
    return dp;
}

//-------------------------------
// Define basic matrix operations
//-------------------------------


