#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../include/taylor.h"
#include "../include/euler.h"

double f(double t, double y) { return y;}

int main(int argc, char *argv[]) {

	double b = euler(f, 0, 1, 1, 4);
	printf("%lf\n", b);

	return 0;
}
