#include "../inc/uls.h"

void mx_printint_err(int n) {
    if (n == -2147483648) {
        mx_printerr_c('-');
        mx_printerr_c('2');
        mx_printint(147483648);
    }
    else if (n < 0) {
        mx_printerr_c('-');
        mx_printint(n *= -1);
    }
    else if (n < 10) {
        mx_printerr_c(n + 48);
    }
    else {
        mx_printint(n / 10);
        mx_printerr_c(n % 10 + 48);
    }
}
