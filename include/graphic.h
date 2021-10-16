#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef GRAPHIC_H
#define GRAPHIC_H

// Two lists of all the pais (t, y), and n number of elements (length is n+1)
typedef struct table2D Table2D;
struct table2D {
    double *ts;
    double *ys;
    int n;
};

int plotODE(struct table2D **tab, int num);

#endif
