#include "../inc/uls.h"

int mx_isfileR(char *argv) {
    struct stat buf;
    char *temp1 = mx_strdup(argv);

    lstat(temp1, &buf);
    if (MX_ISDIR(buf.st_mode)) { //  (buf.st_mode & S_IFMT) == S_IFDIR
        free(temp1);
        return 0;
    }
    else {
        if (!MX_ISDIR(buf.st_mode)) {
            free(temp1);
            return 1;
        }
    }
    free(temp1);
    return -2;
}
