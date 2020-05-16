#include "../inc/uls.h"

int mx_find_max_se(char **mass, char *name, char c) {
    int k = 0;
    char *path;
    struct stat sb;
    struct passwd *pw;

    for (int l = 0; mass[l] != NULL; l++) {
        path = mx_make_path(mass[l], name, 0, 0);
        lstat(path, &sb);
        if (c != 'n') {
            pw = getpwuid(sb.st_uid);
            if (mx_strlen(pw->pw_name) > k)
                k = mx_strlen(pw->pw_name);
        }
        else
            if (mx_numlen(sb.st_uid) > k)
                k = mx_numlen(sb.st_uid);
        mx_strdel(&path);
    }
    return k;
}
