#include "../inc/uls.h"

char *mx_dec_to_hex(int dec) {
    int quotient = dec;
    int remainder;
    char *hex = (char *)malloc(sizeof(char) * 100);
    int j = 0;

    while (quotient != 0) {
        remainder = quotient % 16;
        if (remainder < 10)
            hex[j++] = 48 + remainder;
        else
            hex[j++] = 87 + remainder;
        quotient = quotient / 16;
    }
    hex[j] = '\0';
    return hex;
}
