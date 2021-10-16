#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../include/graphic.h"

#ifndef EULER_H
#define EULER_H

double euler(double (*f)(double*), double* ivp, double h, double tn, struct table2D **tab);

#endif
