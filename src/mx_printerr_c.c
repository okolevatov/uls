#include "../inc/uls.h"

void mx_printerr_c(char s) {
    write(2, &s, 1);
}
