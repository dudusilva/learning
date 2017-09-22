#include <stdio.h>

char** encode(char* strng, int shift, int* lg);
char* decode(char** s, int sz);

int main(void) {
    int lg;
    char* u = "I should have known that you would have a perfect answer for me!!!";
    char* sol[5] = {"ijJ tipvme ibw","f lopxo uibu z","pv xpvme ibwf ","b qfsgfdu botx","fs gps nf!!!"};

    //char* sol = "{'ijJ tipvme ibw','f lopxo uibu z','pv xpvme ibwf ','b qfsgfdu botx','fs gps nf!!!'}";

    char** res = encode(u, 1, &lg);
    //char* res = decode(sol, 5);
}

                
