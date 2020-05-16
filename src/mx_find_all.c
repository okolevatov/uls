#include "../inc/uls.h"

char **mx_find_all(char **name, int k) {
    struct stat sb;
    char **files;
    int minus_k = 0;

    for (int i = 0; i < k; i++) {
        lstat(name[i], &sb);
        if (!MX_ISDIR(sb.st_mode))
            minus_k++;
    }
    files = (char **)malloc(sizeof(char *) * minus_k + 1);
    minus_k = 0;
    for (int i = 0; i < k; i++) {
        lstat(name[i], &sb);
        if (!MX_ISDIR(sb.st_mode))
            files[minus_k++] = mx_strdup(name[i]);
    }
    files[minus_k] = NULL;
    return files;
}
