#include "../inc/uls.h"

static int major_my(unsigned int num) {
    int c = 0;

    c = num >> 24;
    return c;
}

static int minor_my(unsigned int num) {
    int c = 0;

    c = num & (1U << 24) - 1;
    return c;
}

static void minor_output(int j, int rdev) {
    for (j = 0; (j + mx_numlen(minor_my(rdev))) != 3; j++)
        mx_printchar(' ');
    mx_printint(minor_my(rdev));
}

void mx_file_size(int mode, unsigned int rdev, int size) {
    int k;
    int j;

    if (MX_ISCHR(mode) || MX_ISBLK(mode)) {
        for (j = 0; (j + mx_numlen(major_my(rdev))) != 3; j++)
            mx_printchar(' ');
        mx_printint(major_my(rdev));
        mx_printstr(", ");
        if ((k = minor_my(rdev)) > 255) {
            mx_printstr("0x");
            for (j = 0; (j + mx_strlen(mx_dec_to_hex(k))) != 8; j++)
                mx_printchar('0');
            mx_printstr(mx_dec_to_hex(k));
        }
        else
            minor_output(j, rdev);
    }
    else
        mx_printint(size);
}
