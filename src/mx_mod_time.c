#include "../inc/uls.h"

void mx_mod_time(time_t mtime, char k) {
    time_t six_months = mtime;
    time_t now = time(&now);
    int t = 4;
    char *s;

    mx_printchar(' ');
    s = ctime(&mtime);
    if (k == 'T')
        for (; t < mx_strlen(s) - 1; t++)
            mx_printchar(s[t]);
    else if (now - six_months > 15778000) {
        for (; t < 11; t++)
            mx_printchar(s[t]);
        for (t = 19; t < mx_strlen(s) - 1; t++)
            mx_printchar(s[t]);
    }
    else
        for (; t < 16; t++)
            mx_printchar(s[t]);
}
