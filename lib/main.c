#include "../include/main.h"

double f(double* x) { return x[0]*x[1] + exp(x[1]/10)/(x[0]+1);}

int main(int argc, char *argv[]) {

	double pvi[2] = {0, 3};
	struct table2D *table1;

	taylor2(f, pvi, 0.1, 2, &table1);

	for (int i = 0; i <= table1->n; i++) {
		printf("%lf %lf\n", table1->ts[i], table1->ys[i]);
	}



	/*double pvi2[2] = {0, 1};
	struct table2D *table2;

	taylor2(f, pvi2, 2, 2, &table2);
	printf("%lf %lf \n", table2->ts[table2->n], table2->ys[table2->n]);*/

	return 0;
}
