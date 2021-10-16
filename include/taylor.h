#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../include/differentiation.h"
#include "../include/graphic.h"



double taylor2(double (*f)(double*), double* ivp, double h, double tn, struct table2D **tab);
