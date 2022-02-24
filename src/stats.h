#ifndef STATS
#define STATS

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

extern double mininum(const double x[]);
extern double maximum(const double x[]);
extern double sum(const double x[]);
extern double mean(const double x[]);
extern double var(const double x[]);
extern double sd(const double x[]);
extern double pearson_corr(const double x[], const double y[]);
extern double spearman_corr(const double x[], const double y[]);
extern double autocorr(const double x[]);

#endif