typedef unsigned long long ull;

char* dec2FactString(ull nb);
ull factString2Dec(char* str);

int main(void) {
    ull res_ul;
    char *res_ch;
    char inp_ch[] = "341010";
    ull inp_ul = 34303;

    res_ch = dec2FactString(inp_ul);

    return 0;
}
