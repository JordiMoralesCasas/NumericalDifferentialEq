#include "../include/euler.h"

/**
 * Euler method for numerically approximating ordinary differential equation
 * solutions.
 *
 * @param f     differential equation f([t, y])
 * @param ivp   initial value problem [t0, y0]
 * @param h     step used per iteration
 * @param tn    final time after n iterations following tn = t0 + h*n
 * @param tab	table2D structure in which all the generated points will be stored
 */
double euler(double (*f)(double*), double* ivp, double h, double tn, struct table2D **tab)
{
    // TODO: ver que hacer cuando tn < t0, idea negar el paso a -h
    // quizas tambien habria que comprobar que el paso sea positivo
    // Avisar si el vector de la funcion tiene mas de dos variables

    if (tn < ivp[0]) {
        printf("ERROR: final time smaller than initial time (tn < t0).\n");
        return -1;
    }
    if (h <= 0) {
        printf("ERROR: step (h) has to be a positive number.\n");
        return -1;
    }

    int n = (tn - ivp[0])/h;	 // Number of steps. Adding h is necessary
                                     // in order to avoid truncation errors in
                                     // the number of steps

    //Initializing auxiliar table structure. Every generated point will be stored here
	struct table2D *aux_tab = malloc(sizeof(Table2D));
	aux_tab->ts = malloc(n * sizeof(double));
	aux_tab->ys = malloc(n * sizeof(double));
	aux_tab->n = n;

    //Storing initial positon
	aux_tab->ts[0] = ivp[0];
	aux_tab->ys[0] = ivp[1];


    double *pnt_i = malloc(2 * sizeof(double)); // pni_i represents the current state of the
    pnt_i[0] = ivp[0], pnt_i[1] = ivp[1];       // approximation. Starts with the ivp

    for (int i = 1; i <= n; i++){
        pnt_i[1] = pnt_i[1] + h*(*f)(pnt_i);
        pnt_i[0] = pnt_i[0] + h;

        aux_tab->ts[i] = pnt_i[0];
		aux_tab->ys[i] = pnt_i[1];
    }

    //Returns the results table and the final yn value
	*tab = aux_tab;
    return pnt_i[1];
}
