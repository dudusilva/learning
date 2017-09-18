double going(int n) {
    double sum = 1;
    double den = 1;

    for (int i=n;i>1;i--) {
        den /= i;
        sum = sum + den; 
    }

    return sum;
}

