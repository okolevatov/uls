#include "../inc/uls.h"


static char **indir(char *name, t_argv *all) {
    char **mass2 = NULL;
    int i = 0;

    errno = 0;
    mass2 = mx_cr_no_kol(name, all, 0);
    if (mass2 != NULL) {
        while (mass2[i] != NULL)
            i++;
        mx_sort_flags(mass2, i, all, name);
    }
    return mass2;
}

void mx_one_m(char **mass, t_argv *all) {
    char **array = NULL;

    if (mx_isfile(mass[0]) == 1) {
            mx_printstr(mass[0]);
            mx_printchar('\n');
    }
    else {
        array = indir(mass[0], all);
        if (array != NULL) {
            mx_output_m(array, 0, 0);
            mx_printchar('\n');
        }
    }
    if (array != NULL)
        mx_del_strarr(&array);
}
