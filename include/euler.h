#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include "../include/graphic.h"

double euler(double (*f)(double*), double* ivp, double h, double tn, struct table2D **tab);
