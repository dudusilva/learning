#include<stdlib.h>
#include<math.h>

#define FRAC 2
#define SWAP(a,b) a^=b; b^=a; a^=b;

static long long gcd(long long a, long long b) {
    while (b) {
        a %= b;    
        SWAP(a,b); 
    }
    return a;
}

static long long lcm(long long a, long long b) {
    long long mul = a*b;
    long long div = gcd(a,b);
    return mul/div;
}

static void reduce(long long *num, long long *den) {
    long long common = gcd(*num, *den);
    *num /= common;
    *den /= common;
}

long long** convertFrac(long long lst[][2], int row) {
    long long *res = malloc(row*FRAC*sizeof(long long));

    if (row) {
        long long common = 1;

        for (int i=0;i<row;i++) {
            reduce(*(lst+i)+0, *(lst+i)+1);
            common = lcm(common, *(*(lst+i)+1));
        }

        for (int i=0;i<row;i++) {
            long long mul = common / *(*(lst+i)+1);

            *(res+i*FRAC+0) = mul * *(*(lst+i)+0);
            *(res+i*FRAC+1) = common;
        }
    }

    return (long long **) res;
}

/*
for (int i=0;i<row;i++) {
    printf("{%lld %lld} ", *(*(lst+i)+0), *(*(lst+i)+1));
}
printf("\n");

printf("lcm %lld\n", common);        
long long nu0 = 12;
long long nu1 = 80;
printf("gcd %lld\n", gcd(nu0, nu1));        
printf("lcm %lld\n", lcm(nu0, nu1));        
*/

