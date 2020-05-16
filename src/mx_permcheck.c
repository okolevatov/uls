#include "../inc/uls.h"

static void *memrchr(const void *s, int c, size_t n) {
    const char *str = s;

    for (size_t i = n - 1; i > 0; i--)
        if (str[i] == c)
            return (void*) &str[i + 1];
    return (void*) str;
}

int mx_permcheck(char *argv, t_argv *all) {
    DIR *dir;
    errno = 0;

    dir = opendir(argv);
    if (errno == 13) {
        mx_printerr("uls: ");
        mx_printerr(memrchr((argv), '/', mx_strlen(argv)));
        mx_printerr(": Permission denied\n");
        all->err = 1;
        return -1;
    }
    closedir(dir);
    return 0;
}
