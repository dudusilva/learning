#include <stdlib.h> /* malloc */
#include <math.h> /* sqrt */

#define MAX_FACT 4 /* max. num. of different prime factors */
#define SZ_PRIMES 54 /* num. of different primes */

typedef struct PrimeTable_tag {
    int prime;
    int multiplicity;
    int occurrences;
} PrimeTable;

/* get base factorization with multiplicity */
static PrimeTable* getListPrimeFactors(int base) {
    const int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,
                           37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 
                           79, 83, 89, 97, 101, 103, 107, 109, 113,
                           127, 131, 137, 139, 149, 151, 157, 163,
                           167, 173, 179, 181, 191, 193, 197, 199,
                           211, 223, 227, 229, 233, 239, 241, 251 };
    PrimeTable* list = malloc(sizeof(PrimeTable)*MAX_FACT);
    PrimeTable* ptr = list;

    for (int i=0;i<MAX_FACT;i++) { list[i].prime = 0; }

    for (int i=0;i<SZ_PRIMES;i++) {
        if (base%primes[i] == 0) {
            int mult = 1;
            int aux = base/primes[i];

            while (aux%primes[i] == 0) {
                mult++;
                aux /= primes[i];
            }

            ptr->prime = primes[i];
            ptr->multiplicity = mult;
            ptr->occurrences = 0;
            ptr++; 
        }
    }
    return list;
}

/* fill table with the multiplicity of base prime factors 
   in (number)! */
static void fillListPrimeFactors(PrimeTable* list, int number) {
    for (int i=0;i<MAX_FACT;i++) {
        if (list[i].prime) {
            int prime = list[i].prime;

            for (int j=prime;j<=number;j+=prime) {
                int aux = j/prime;

                list[i].occurrences++;

                while (aux%prime == 0) {
                    aux /= prime;
                    list[i].occurrences++;
                }
            }
        }
    }
    return;
}

static int numZeroes(PrimeTable* list, int base) {
    int res = 0;

    while (1) {
        for (int i=0;i<MAX_FACT;i++) {
            if (list[i].prime && 
                list[i].multiplicity > list[i].occurrences) {
                return res; 
            } else {
                list[i].occurrences -= list[i].multiplicity;
            }
        }
        res++;
    } 

    return res;
}

int zeroes (int base, int number) {
    PrimeTable* list = getListPrimeFactors(base);
    fillListPrimeFactors(list, number);
    return numZeroes(list, base);
}



    /*
    printf("b: %d f: ", base);
    for (int i=0;i<MAX_FACT;i++) {
        if (*(list+2*i) != -1) { printf("%d ", *(list+2*i)); }        
    }
    printf("\n");
    */
    
