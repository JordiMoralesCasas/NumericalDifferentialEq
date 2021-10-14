#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../include/taylor.h"
#include "../include/euler.h"
#include "../include/differentiation.h"

double f(double* x) { return pow(x[0]*x[1], 4) + 2*x[0] + exp(x[0])*x[1];}

int main(int argc, char *argv[]) {

	double vars[2] = {2,3};

	double a = forward_derivative(f, vars, 0, 2);
	printf("%0.24lf\n", a);

	double b = backward_derivative(f, vars, 0, 2);
	printf("%0.24lf\n", b);

	double c = central_derivative(f, vars, 0, 2);
	printf("%0.24lf\n", c);

	return 0;
}
