#include "../inc/uls.h"

int mx_find_max_s(char *name, char c) {
    struct stat sb;
    struct passwd *pw;
    int k = 0;

    lstat(name, &sb);
    pw = getpwuid(sb.st_uid);
    if (c != 'n') {
        k = mx_strlen(pw->pw_name);
    }
    else {
        k = mx_numlen(sb.st_uid);
    }
    return k;
}
