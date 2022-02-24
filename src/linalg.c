#include <stdio.h>
#include <stdlib.h>

//-------------------------------
// Define basic vector operations
//-------------------------------

// Vector addition

const double vector_add(const double x[], const double y[]){

    int nx = x.size();
    int ny = y.size();

    if(nx != ny){
        return;
    }

    const double z[n];

    for(int i = 0; i < n; i++){
        z[i] = x[i] + y[i];
    }
    return z;
}

// Vector subtraction

const double vector_add(const double x[], const double y[]){

    int nx = x.size();
    int ny = y.size();

    if(nx != ny){
        return;
    }

    const double z[n];

    for(int i = 0; i < nx; i++){
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

    int nx = x.size();
    int ny = y.size();

    if(nx != ny){
        return;
    }

    double dp = 0.0;

    for(int i = 0; i < nx; i++){
        dp += x[i] * y[i];
    }
    return dp;
}

//-------------------------------
// Define basic matrix operations
//-------------------------------

// Matrix addition

void matadd(double a[][], double b[][]) {

    int rowA = A.size() / A.size([0]);
    int colA = A.size() / A.size([0]);
    int rowB = B.size() / B.size([0]);
    int colB = B.size() / B.size([0]);

    if(rowA != rowB){
        return;
    }

    if(colA != colB){
        return;
    }

    double C[rowA][colA];

    // Perform calculations

    for(int i = 0; i < rowA; i++){
        for(int j = 0; j < colA; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

// Matrix multiplication

void matmul(double A[][], double B[][]) {

    int rowA = A.size() / A.size([0]);
    int colA = A.size() / A.size([0]);
    int rowB = B.size() / B.size([0]);
    int colB = B.size() / B.size([0]);

    if(rowA != colB){
        return;
    }

    if(colA != rowB){
        return;
    }

    double C[rowA][colB];

    // Perform calculations

    for(int i = 0; i < rowA; i++){
        for(int j = 0; j < colB; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}
