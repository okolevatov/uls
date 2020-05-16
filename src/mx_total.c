#include "../inc/uls.h"

void mx_total(char **mass, char *name) {
    char *path;
    struct stat sb;
    int k = 0;
    int i;

    for (i = 0; mass[i] != NULL; i++) {
        path = mx_make_path(mass[i], name, 0, 0);
        lstat(path, &sb);
        k += sb.st_blocks;
        mx_strdel(&path);
    }
    if (i != 0) {
        mx_printstr("total ");
        mx_printint(k);
        mx_printchar(10);
    }
}
