typedef struct Pair Pair;

struct Pair {
    long long first;
    long long snd;
};

Pair** solEquaStr(long long n, int* length);

int main(void) {
    long long n = 5;
    int len;
    Pair **res;

    res = solEquaStr(n, &len);

    return 0;
}

