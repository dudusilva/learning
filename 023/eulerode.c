#include<math.h>

#define T 1.0
#define TRN 1e6

double exEuler(int nb) {
    double h = T/nb;  
    double x0 = 0;
    double y0 = 1;
    double err = 0;

    for (int i=0;i<nb;i++) {
        double x1 = x0 + h;
        double z1 = 1 + 0.5*exp(-4*x1) - 0.5*exp(-2*x1);
        double y1 = y0 + (2 - exp(-4*x0) - 2*y0) * h;

        x0 = x1;
        y0 = y1;

        err += fabs(y1-z1)/z1;
    } 

    err /= nb+1;
    err = roundf((int)(err*TRN));
    err /= TRN;

    return err;
}

/*
printf("%f : %f (%f)\n", z1, y1, err/(i+2));
 * Y = [1.0,0.9..,0.85..,0.83..,0.83..,0.85..,0.86..,0.88..,0.90..,0.91..,0.93..]
 * Z = [1.0,0.9..,0.88..,0.87..,0.87..,0.88..,0.89..,0.90..,0.91..,0.93..,0.94..]
 * Relative errors = [0.0,0.02.,0.04..,0.04..,0.04..,0.03..,0.03..,0.02..,0.01..,0.01..,0.01..]
 */
