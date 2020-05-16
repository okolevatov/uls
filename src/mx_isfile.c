#include "../inc/uls.h"

int mx_isfile(char *argv) {
    struct stat buf;
    DIR *dir;
    char *temp1 = mx_strdup(argv);

    lstat(temp1, &buf);
    if (MX_ISLNK(buf.st_mode))
        stat(temp1, &buf);
    if (MX_ISDIR(buf.st_mode)) {
        dir = opendir(temp1);
        free(temp1);
        if (!dir)
            return 0; //заменила -2 на 0
        closedir(dir);
        return 0;
    }
    else {
        free(temp1);
        if (!MX_ISDIR(buf.st_mode))
            return 1;
    }
    return 0; //заменила -2 на 0
}
