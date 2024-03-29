#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//-------------------------
// Basic summary statistics
//-------------------------

// Minimum

double mininum(const double x[]){

    int n = x.size();
    double m = x[0];

    for (int i = 1; i < n; i++) {
        if (x[i] < m) {
            m = x[i];
        }
    }
    return m;
}

// Maximum

double maximum(const double x[]){

    int n = x.size();
    double m = x[0];

    for (int i = 1; i < n; i++) {
        if (x[i] > m) {
            m = x[i];
        }
    }
    return m;
}

// Sum

double sum(const double x[]){

    int n = x.size();
    double sigma = 0.0;

    for (int i = 0; i < n; i++) {
        sigma += x[i];
    }
    return sigma;
}

// Mean

double mean(const double x[]){

    int n = x.size();
    double sigma = sum(x);
    double xbar = sigma / n;
    return xbar;
}

// Variance

double var(const double x[]){

    int n = x.size();
    double s_squared = 0.0;
    double xbar = mean(x);

    for (int i = 0; i < n; i++) {
        s_squared += (x[i]-xbar)*(x[i]-xbar);
    }
    
    return s_squared
}

// Standard deviation

double sd(const double x[]){

    int n = x.size();
    double s_squared = var(x);
    double s = sqrt(s_squared);
    return s;
}

//--------------------
// Statistical methods
//--------------------

// Pearson correlation

double pearson_corr(const double x[], const double y[]){

    int n = x.size();
    double xbar = mean(x);
    double ybar = mean(y);
    double numerator = 0.0;
    double denominator = sqrt(var(x)) * sqrt(var(y));

    // Calculate numerator

    for (int i = 0; i < n; i++) {
        numerator += (x[i]-xbar) * (y[i]-ybar);
    }
    
    // Return Pearson correlation coefficient

    double r = numerator / denominator;
    return r;
}

// Autocorrelation

double autocorr(const double x[], int lag){

    int n = x.size();
    double xbar = mean(x);
    double variance = var(x);
    double autocovar, acf;

    // Compute lag covariance

    for (int i = 0; i < n-lag; i++) {
        autocovar += (x[i]-xbar)*(x[i+1]-xbar);
  }

  // Return autocorrelation function

  acf = autocovar/variance;
  return acf;
}
