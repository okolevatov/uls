#include "../inc/uls.h"

int mx_numlen (int n) {
    int k = 0;

    if (n == 0)
        return 1;
    while (n > 0) {
        n /= 10;
        k++;
    }
    return k;
}
