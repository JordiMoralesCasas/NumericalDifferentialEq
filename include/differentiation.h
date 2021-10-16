#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef DIFFERENTIATION_H
#define DIFFERENTIATION_H

double forward_derivative(double (*f)(double*), double* pnt, int var, int n_vars);

double backward_derivative(double (*f)(double*), double* pnt, int var, int n_vars);

double central_derivative(double (*f)(double*), double* pnt, int var, int n_vars);

#endif
