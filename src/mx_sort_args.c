#include "../inc/uls.h"

void mx_sort_args(char *argv[], int argc) {
    char *s = NULL;

    for (int j = 1; j < argc; j++) {
        for (int i = 1; i < argc - 1; i++) {
            if (mx_strcmp(argv[i],argv[i + 1]) > 0) {
                s = argv[i + 1];
                argv[i + 1] = argv[i];
                argv[i] = s;
            }
        }
    }
}
