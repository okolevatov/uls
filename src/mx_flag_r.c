#include "../inc/uls.h"

void mx_flag_r(char **mass, int kol) {
    char *buff = NULL;
    int j = kol - 1;

    for (int i = 0; i < kol / 2; i++) {
        buff = mx_strdup(mass[i]);
        free(mass[i]);
        mass[i] = mx_strdup(mass[j]);
        free(mass[j]);
        mass[j] = mx_strdup(buff);
        j--;
        free(buff);
    }
}
