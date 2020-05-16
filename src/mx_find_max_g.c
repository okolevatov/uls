#include "../inc/uls.h"

static int auditor (int k, char *path, char c) {
    struct group *gr;
    struct stat sb;

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

int mx_find_max_g(char **mass, char *name, char c) {
    char *path;
    int k = 0;

    for (int i = 0; mass[i] != NULL; i++) {
        path = mx_make_path(mass[i], name, 0, 0);
        k = auditor(k, path, c);
        mx_strdel(&path);
    }
    return k;
}
