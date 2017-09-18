#include <stdlib.h> /* malloc, calloc */

double doubles(int maxk, int maxn) {
    double *base = malloc(maxn*sizeof(double));
    double *aux = malloc(maxn*sizeof(double));
    double final_sum = 0;

    for (int i=0;i<maxn;i++) { *(aux+i) = 1.0; }
    for (int i=0;i<maxn;i++) { *(base+i) = 1.0/((i+2)*(i+2)); }

    for (int i=0;i<maxk;i++) {
        double partial_sum = 0;

        for (int j=0;j<maxn;j++) {
            *(aux+j) *= *(base+j);
            partial_sum += *(aux+j);
        } 
        
        final_sum += partial_sum/(i+1.0); 
    }
    return final_sum;
}

