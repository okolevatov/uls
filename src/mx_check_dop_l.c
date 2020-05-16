#include "../inc/uls.h"

char *mx_check_dop_l(char *flag) {
    char *s =(char *)malloc(sizeof(char) * 6);
    int i;

    for (i = 0; i < 6; i++)
        s[i] = 'x';
    s[i] = '\0';
    for (i = 0; flag[i]; i++) {
        if (flag[i] == 'g')
            s[0] = 'g';
        else if (flag[i] == 'n')
            s[1] = 'n';
        else if (flag[i] == 'o')
            s[2] = 'o';
        else if (flag[i] == 'T')
            s[3] = 'T';
        else if (flag[i] == 'd')
            s[4] = 'd';
    }
    return s;
}
