#include "../include/taylor.h"


/**
 * 2nd order Taylor series method for differential equations
 *
 * @param f     differential equation f(t, y)
 * @param pnt   point where the derivative is evaluated. pnt[0] should be the
 				time variable and pnt[1] the image variable
 * @param h     step used per iteration
 * @param tn    final time after n iterations following tn = t0 + h*n
 * @param tab	table2D structure in which all the generated points will be stored
 */
 double taylor2(double (*f)(double*), double* ivp, double h, double tn, struct table2D **tab)
{
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


    // Start the iterative method following the second order taylor series:
    //   y_{i+1} = y_i + h*f(t_i, y_i) + h^2/2*[Dtf(t_i, y_i) + Dyf(t_i, y_i)*f(t_i, y_i)]
    //   t_{i+1} = t_i + h
    for (int i = 1; i <= n; i++){
        pnt_i[1] = pnt_i[1] + h*(*f)(pnt_i)+ h*h / 2 *
				(
				 central_derivative(f, pnt_i, 0, 2) +
				 central_derivative(f, pnt_i, 1, 2)*f(pnt_i)
			 	);
        pnt_i[0] = pnt_i[0] + h;

		aux_tab->ts[i] = pnt_i[0];
		aux_tab->ys[i] = pnt_i[1];

    }

    //Returns the results table and the final yn value
	*tab = aux_tab;
    return pnt_i[1];
}
