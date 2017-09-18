
int nbYear(int p0, double percent, int aug, int p) {
    const double per = 1+percent/100.0;

    for (years=0;p0<p;years++) { p0 = p0*per+aug; }

    return years;
}

