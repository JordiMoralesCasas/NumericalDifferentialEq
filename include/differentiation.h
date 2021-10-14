#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double forward_derivative(double (*f)(double*), double* pnt, int var, int n_vars);

double backward_derivative(double (*f)(double*), double* pnt, int var, int n_vars);

double central_derivative(double (*f)(double*), double* pnt, int var, int n_vars);
