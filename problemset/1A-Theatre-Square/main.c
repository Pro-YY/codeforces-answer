/*
 * http://codeforces.com/problemset/problem/1/A
 * Apr 20, 2016
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int process(long n, long m, long a) {
    double r = (ceil((double)n/a))*(ceil((double)m/a));
    printf("%0.0lf\n", r);
    return 0;
}

int main(int argc, char *argv[]) {
    long n, m, a;
    while (scanf("%ld%ld%ld", &n, &m, &a) != EOF) {
        process(n, m, a);
    }
    return EXIT_SUCCESS;
}
