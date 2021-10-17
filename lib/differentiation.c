#include "../include/differentiation.h"

/**
 * Forward difference method for numerical differentiation
 *
 * @param f     function to differentiate
 * @param pnt   point where the derivative is evaluated
 * @param var   variable with respect the function is differenciate
 * @param n_vars   variable with respect the function is differenciate
 */
double forward_derivative(double (*f)(double*), double* pnt, int var, int n_vars)
{
    // TODO: comprobar que var no se salga del rango
    if (var >= n_vars) {
        printf("ERROR: Cannot get the derivative with respect to the specified variable (var is greater than the number of variables) \n");
        return -1;
    }


    // h represents a small change in the variable of interest
    double h =
        pnt[var] != 0 ? sqrt(__DBL_EPSILON__)*pnt[var] : sqrt(__DBL_EPSILON__)*1e-5;

    // generate a new variables vector after taking an h-step
    double* inc_x = malloc(n_vars * sizeof(double));
    for (int i = 0; i < n_vars; i++) inc_x[i] = pnt[i]; // copy content of pnt to inc_x
    inc_x[var] += h;

    return ((*f)(inc_x) - (*f)(pnt)) / h;
}



/**
 * Backward difference method for numerical differentiation
 *
 * @param f     function to differentiate
 * @param pnt   point where the derivative is evaluated
 * @param var   variable with respect the function is differenciate
 * @param n_vars   variable with respect the function is differenciate
 */
double backward_derivative(double (*f)(double*), double* pnt, int var, int n_vars)
{
    if (var >= n_vars) {
        printf("ERROR: Cannot get the derivative with respect to the specified variable (var is greater than the number of variables) \n");
        return 0;
    }


    // h represents a small change in the variable of interest
    double h =
        pnt[var] != 0 ? sqrt(__DBL_EPSILON__)*pnt[var] : sqrt(__DBL_EPSILON__)*1e-5;

    // generate a new variables vector after taking an h-step
    double* dec_x = malloc(n_vars * sizeof(double));
    for (int i = 0; i < n_vars; i++) dec_x[i] = pnt[i]; // copy content of pnt to inc_x
    dec_x[var] -= h;

    return ((*f)(pnt) - (*f)(dec_x)) / h;
}



/**
 * Central difference method for numerical differentiation.
 *
 * @param f     function to differentiate
 * @param pnt   point where the derivative is evaluated
 * @param var   variable with respect the function is differenciate
 * @param n_vars   variable with respect the function is differenciate
 */
double central_derivative(double (*f)(double*), double* pnt, int var, int n_vars)
{
    // TODO: comprobar que var no se salga del rango
    if (var >= n_vars) {
        printf("ERROR: Cannot get the derivative with respect to the specified variable (var is greater than the number of variables) \n");
        return 0;
    }


    // h represents a small change in the variable of interest
    double h = cbrt(__DBL_EPSILON__);

    // generate a new variables vector after taking an h-step
    double* inc_x = malloc(n_vars * sizeof(double));
    for (int i = 0; i < n_vars; i++) inc_x[i] = pnt[i]; // copy content of pnt to inc_x
    inc_x[var] += h;

    double* dec_x = malloc(n_vars * sizeof(double));
    for (int i = 0; i < n_vars; i++) dec_x[i] = pnt[i]; // copy content of pnt to inc_x
    dec_x[var] -= h;

    return ((*f)(inc_x) - (*f)(dec_x)) / (2*h);
}
