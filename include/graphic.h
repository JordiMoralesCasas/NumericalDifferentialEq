#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Two lists of all the pais (t, y), and n number of elements (length is n+1)

#ifndef GRAPHIC_H
#define GRAPHIC_H

typedef struct table2D Table2D;

struct table2D {
    double *ts;
    double *ys;
    int n;
};

#endif
