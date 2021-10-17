#include "../include/main.h"

double f1(double* x) { return x[0]*x[1];}

double f2(double* x) { return x[0]*x[1];}

int main(int argc, char *argv[]) {

	double pvi1[2] = {0, 1};
	struct table2D *table1;
	taylor2(f1, pvi1, 0.01, 2, &table1);

	double pvi2[2] = {0, 1};
	struct table2D *table2;
	taylor2(f2, pvi2, 0.4, 2, &table2);

	double pvi3[2] = {0, 1};
	struct table2D *table3;
	taylor2(f2, pvi3, 1, 2, &table3);

	struct table2D **list = malloc(3 * sizeof(table1));
	list[0] = table1; list[1] = table2; list[2] = table3;

	plotODE(list, 3);

	showTable(table1);

	return 0;
}
