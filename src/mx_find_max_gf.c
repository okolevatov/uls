#include "../inc/uls.h"

int mx_find_max_gf(char *path, char c) {
    struct stat sb;
    struct group *gr;
    int k = 0;

    lstat(path, &sb);
    if (c == 'n') {
        if (mx_numlen(sb.st_gid) > k)
            k = mx_numlen(sb.st_gid);
    }
    else if ((gr = getgrgid(sb.st_gid)) != 0) {
        if (mx_strlen(gr->gr_name) > k)
            k = mx_strlen(gr->gr_name);
    }
    else {
        if (mx_numlen(sb.st_gid) > k)
            k = mx_numlen(sb.st_gid);
    }
    return k;
}
