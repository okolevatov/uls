#include "../inc/uls.h"

void mx_file_owner(char c, char f, int uid) {
    struct passwd *pw;
    int k = 0;

    pw = getpwuid(uid);
    if (c != 'n') {
        mx_printstr(pw->pw_name);
        if (f != -1)
            for (; (k + mx_strlen(pw->pw_name)) != f; k++)
                mx_printchar(' ');
    }
    else {
        mx_printint(uid);
        if (f != -1)
            for (; (k + mx_numlen(uid)) != f; k++)
                mx_printchar(' ');
    }
}
