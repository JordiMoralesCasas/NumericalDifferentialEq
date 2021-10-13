#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double euler(double (*f)(double, double), double t0, double y0, double h, double tn);
