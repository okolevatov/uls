#include "../inc/uls.h"

void mx_num_hard(int f, int nlink) {
    int k = 0;

    if (f != -1)
        while ((k + mx_numlen(nlink)) != f) {
            mx_printchar(' ');
            k++;
        }
    mx_printchar(' ');
    mx_printint(nlink);
    mx_printchar(' ');
}
