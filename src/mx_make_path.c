#include "../inc/uls.h"

char *mx_make_path(char *massel, char *namedir, int h, int k) {
    int i = mx_strlen(massel);
    int j;
    char *arr = NULL;

    if (namedir != NULL) {
        j = mx_strlen(namedir);
        arr = (char*)(malloc)(sizeof(char) * (i + j + 2));
        for (; h < j; h++)
            arr[h] = namedir[h];
        arr[h] = '/';
        h++;
        for (;h < i + j + 1; h++) {
            arr[h] = massel[k];
            k++;
        }
        arr[h] = '\0';
        return arr;
    }
    else
        return massel;
}
