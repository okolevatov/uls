#include "../inc/uls.h"

int mx_find_max_n(char **mass, char *name) {
    char *path;
    struct stat sb;
    int k = 0;

    for (int i = 0; mass[i] != NULL; i++) {
        path = mx_make_path(mass[i], name, 0, 0);
        lstat(path, &sb);
        if (sb.st_nlink > k)
            k = sb.st_nlink;
        mx_strdel(&path);
    }
    k = mx_numlen(k);
    return k;
}
