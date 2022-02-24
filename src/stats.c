#include <math.h>
#include <stdio.h>
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
    double xbar = mean(x);
    double s_squared = 0.0;

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

// Kurtosis

double kurtosis(const double x[]){

    int n = x.size();
    double mu = mean(x);

    // Calculate fourth moment

    double moment4 = 0.0;

    for (int i = 0; i < n; ++i) {
        moment4 += (x[i]-mu)*(x[i]-mu)*(x[i]-mu)*(x[i]-mu);
    }

    // Calculate second moment

    double moment2 = 0.0;

    for (int i = 0; i < n; ++i) {
        moment2 += (x[i]-mu)*(x[i]-mu);
    }

    // Calculate kurtosis

    double r = n * moment4 / (moment2 * moment2);
    double kurtosis = r * ((1 - 1 / n) * (1 - 1 / n)) - 3;
    return kurtosis;
}

// Skewness

double skewness(const double x[]){

    int n = x.size();
    double mu = mean(x);
    double sigma = sd(x);

    // Calculate G

    double G = sqrt((n*(n-1)))/(n-2);

    // Calculate skewness

    double total_skew = 0.0;

    for (int i = 0; i < n; ++i) {
        total_skew += ((x[i]-mu)*(x[i]-mu)*(x[i]-mu))/n;
    }

    double skewness = total_skew / (sigma * sigma * sigma);

    // Adjust skewness

    double adj_skewness = G * skewness;
    return adj_skewness;
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

// Spearman correlation

double spearman_corr(const double x[], const double y[]){

    int n = x.size();

    // Sort and rank x and y vectors

    const int x_rank[n];
    const int y_rank[n];

    //

    // Compute squared sum of rank differences

    double d = 0.0;

    for (int i = 0; i < n; i++) {
        d += x_rank[i] - y_rank[i];
    }

    double d_sq = sqrt(d);

    // Return Spearman correlation

    double rho = 1 - ((6 * d_sq) / (n * ((n*n) - 1)));
    return rho;
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
