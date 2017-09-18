#include<stdlib.h> /* malloc */
#include<math.h> /* sqrt */

#define NUMFIELDS 2

struct node {
    int data;
    struct node *next;
};

struct list {
    size_t sz;
    struct node *head;
};

static int insertPrime(int* table, int prime, int start, int idx) {
    *(table) = prime;
    *(table+1) = start % prime;
    return idx + NUMFIELDS;
}

static int isPrime(int num, int* table, int idx) {
    int sqt = sqrt(num);

    while (idx) {
        if (*table <= sqt) {
            if (num % *table == 0) return 0;

            table += 2;
            idx -= 2;
        } else {
            break;
        }
    }
    return 1;
}

static int* buildPrimeTable(int start, int end) {
    int *res = malloc(NUMFIELDS*(end+2)*sizeof(int));
    int idx = 0;

    if (end >= 2) { idx = insertPrime((res+idx), 2, start, idx); }
    if (end >= 3) { idx = insertPrime((res+idx), 3, start, idx); }
    if (end >= 5) { idx = insertPrime((res+idx), 5, start, idx); }

    for (int i=6;i<=end;i+=6) {
        if (isPrime(i+1, res, idx)) {
            idx = insertPrime((res+idx), i+1, start, idx);
        }
        
        if (isPrime(i+5, res, idx)) {
            idx = insertPrime((res+idx), i+5, start, idx);
        }
    }
    *(res+idx) = 0;

    return res;
}

static int getMultiplicity(int num, int prime) {
    int mult = 0;

    while (num % prime == 0) {
        mult++;
        num /= prime;
    }
    return mult;
}

static int getNumFactors(int num, int *table) {
    int res = 0;

    for (int i=0;*(table+i);i+=NUMFIELDS) {
        if (*(table+i+1) == 0) {
            res += getMultiplicity(num, *(table+i));
        }
    }
    return res;
}

static void updateTable(int *table) {
    for (int i=0;*(table+i);i+=NUMFIELDS) {
        (*(table+i+1))++;

        if (*(table+i+1) == *(table+i)) {
            *(table+i+1) = 0;
        }
    }
}

struct list* kPrimes(int k, int start, int nd) {
    int *primes = NULL;
    struct list* res = malloc(sizeof(struct list));
    struct node* tail = NULL;

    (*res).sz = 0;
    (*res).head = NULL;
    if (start < 2) { start = 2; }
    primes = buildPrimeTable(start, nd);

    for (int i=start;i<=nd;i++) {
        int numfactors = getNumFactors(i, primes);

        if (numfactors == k) {
            struct node* ptr = malloc(sizeof(struct node));
            (*ptr).data = i;
            (*ptr).next = NULL;
            
            if (tail == NULL) {
                (*res).head = ptr;
            } else {
                (*tail).next = ptr;
            } 
            tail = ptr;
            (*res).sz++;
        }

        updateTable(primes);
    }

    return res;
}

int puzzle(int s) {
    struct list* primes_1 = kPrimes(1, 1, s);
    struct list* primes_3 = kPrimes(3, 1, s);
    struct list* primes_7 = kPrimes(7, 1, s);
    int numSolutions = 0;

    struct node* ptr_1 = (*primes_1).head;
    for (int i=0;i<(*primes_1).sz;i++) {
        struct node* ptr_3 = (*primes_3).head;
        for (int j=0;j<(*primes_3).sz;j++) {
            struct node* ptr_7 = (*primes_7).head;
            for (int k=0;k<(*primes_7).sz;k++) {
                int sum = (*ptr_1).data + 
                          (*ptr_3).data +
                          (*ptr_7).data;

                if (sum == s) {
                    numSolutions++;
                }
                ptr_7 = (*ptr_7).next;
            }
            ptr_3 = (*ptr_3).next;
        }
        ptr_1 = (*ptr_1).next;
    }
   
    return numSolutions; 
}

/*
            printf("k %d, s %d, e %d\n", k, start, nd);
    printf("s %d\n", s);
        printf("%d : %d\n", i, getNumFactors(i, primes));
    for (int i=0;*(primes+i);i+=NUMFIELDS) {
        printf("%d : %d\n", *(primes+i), *(primes+i+1));
    }
    */
