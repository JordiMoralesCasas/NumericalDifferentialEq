#include "../include/graphic.h"


/**
 * Given an array of 2D tables, calls GNUPLOT so they can be shown in a single plot
 *
 * @param tab   a two dimensional array containing the table2D structures
 * @param num   number of table2D structures
 */
int plotODE(struct table2D **tabs, int num)
{
    FILE * temp = fopen("temp/data.txt", "w"); // Temporal file

    //TODO: comprobaciones de introduccion de datos

    /* All the points have to be written into the temporal file in order to get plotted by GNUPLOT */
    for(int j = 0; j < num; j++) {
        for (int i=0; i < tabs[j]->n; i++)
            fprintf(temp, "%lf %lf\n", tabs[j]->ts[i], tabs[j]->ys[i]); //Write the data to a temporary file

        // Last point written apart so a label can be placed
        fprintf(temp, "%lf %lf %d\n", tabs[j]->ts[tabs[j]->n], tabs[j]->ys[tabs[j]->n], j+1);
        fprintf(temp, "\n\n");
    }

    /*  Opens an interface that one can use to send commands as if they were typing into the
     *  gnuplot command line.
     */
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");

    int numberOfCommands = 5;
    char * commandsForGnuplot[] = { "set title \"\"",
                                    "unset key",
                                    "set ylabel \"Y\"",
                                    "set xlabel \"T\"",
                                    "plot \"temp/data.txt\" u 1:2:(column(-2)) with lines lc variable lw 2,\
                                     '' using 1:2:3 with labels offset -1.5, char 1"
                                  };


    for (int i=0; i < numberOfCommands; i++)
        fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.

    fclose(temp);
    return 0;
}


/**
 * Shows the given table in the console
 *
 * @param tab   a table2D struct containing the information
 */
int showTable(struct table2D *tab)
{
    printf("|| step ||     tn     ||    y(t)    ||\n");
    printf("||------||------------||------------||\n");
    for(int i = 0; i < tab->n; i++)
        printf("||%d\t||  %0.6lf  ||  %0.6lf  ||\n", i, tab->ts[i], tab->ys[i]);

    printf("||------||------------||------------||\n");
    printf("||%d\t||  %0.6lf  ||  %0.6lf  ||\n", tab->n, tab->ts[tab->n], tab->ys[tab->n]);
    printf("||------||------------||------------||\n");


    return 0;
}
