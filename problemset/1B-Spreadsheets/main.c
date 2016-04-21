/*
 * http://codeforces.com/problemset/problem/1/B
 * Apr 21, 2016
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int is_r(const char *str) {
    const char *p = str;
    int flag = 0;
    int flag1 = 0;
    if (*p != 'R') return flag;
    for(p = str + 1; *p; p++) {
        if (isdigit(*p)) {
            flag1 = 1;
            continue;
        }
        if (*p == 'C' && flag1) {
            flag = 1;
            break;
        }
    }
    return flag;
}

void reverse_inplace(char *s) {
    char *p, *q;
    char t;
    p = q = s;
    while (*q) {q++;};
    q--;
    while (p < q) {
        t = *p;
        *p = *q;
        *q = t;
        p++;
        q--;
    }
}

void r_to_a(const char *str) {
    int r = 0;
    int c = 0;
    char s[16] = {0};
    const char *p = str + 1;
    sscanf(p, "%d", &r);
    while (*p++ != 'C') {};
    sscanf(p, "%d", &c);

    int i = 0;
    while (c > 0) {
        if (c%26 == 0) {
            s[i] = 'Z';
            c /= 26;
            c -= 1;
        }
        else {
            s[i] = c%26+'A'-1;
            c /= 26;
        }
        i++;
    }
    reverse_inplace(s);
    printf("%s", s);
    printf("%d\n", r);
}

void a_to_r(const char *str) {
    const char *p = str;
    const char *q = str;
    int r = 0;
    int c = 0;
    int power = 1;
    while (!isdigit(*p)) {p++;};
    sscanf(p, "%d", &r);
    p--;
    while (p >= str) {
        c += (*p - 'A' + 1) * power;
        power *= 26;
        p--;
    }
    printf("R%dC%d\n", r , c);
}

void process(const char *str) {
    if (is_r(str)) r_to_a(str);
    else a_to_r(str);
}

int main(int argc, char *argv[]) {
    int repeat = 0;
    scanf("%d", &repeat);
    char s[32];
    while (repeat-- > 0 && scanf("%s", s) != EOF) {
        process(s);
    }
    return EXIT_SUCCESS;
}
