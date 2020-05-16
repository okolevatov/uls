#include "../inc/uls.h"

static void *memrchr(const void *s, int c, size_t n) {
    const char *str = s;

    for (size_t i = n - 1; i > 0; i--)
        if (str[i] == c)
            return (void*) &str[i + 1];
    return (void*) str;
}

int mx_error_13(int k, char *arr, t_argv *all) {
    if (errno == 13) {
        if (k != 1) {
            mx_printchar(10);
            mx_printstr(arr);
            mx_printstr(":\n");
        }
        mx_printerr("uls: ");
        mx_printerr(memrchr((arr), '/', mx_strlen(arr)));
        mx_printerr(": Permission denied\n");
        all->err = 1;
        return 0;
    }
    return 1;
}
