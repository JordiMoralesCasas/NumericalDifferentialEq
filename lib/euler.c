#include "../include/euler.h"

/**
 * Euler method for numerically approximating ordinary differential equation
 * solutions.
 *
 * @param f     differential equation f(t, y).
 * @param t0    initial time from the initial value problem.
 * @param y0    initial objective value from the initial value problem.
 * @param h     step used per iteration
 * @param tn    final time after n iterations following tn = t0 + h*n
 */
double euler(double (*f)(double, double), double t0, double y0, double h, double tn)
{
    // TODO: ver que hacer cuando tn < t0, idea negar el paso a -h
    // quizas tambien habria que comprobar que el paso sea positivo

    double yi = y0; //Current solution value. Starts at y0
    double ti = t0; //Current time
    double n = (tn - t0)/h; //number of steps

    for (double i = 1; i <= n+1e-8; i++){
        yi = yi + h*(*f)(ti, yi);
        ti = ti + h;
    }
    return yi;
}
