#include "../inc/uls.h"

static int len_of_arr(char **arrd) {
    int i = 0;

    while(arrd[i] != NULL)
        i++;
    return i;
}

static void entry_in(int i, char **mass, t_argv *all, char **arrd) {
    DIR *dir;
    int p = 0;
    struct dirent *entry;

    dir = opendir(arrd[i]);
    if (mx_error_13(1, arrd[i], all)) {
        while ((entry = readdir(dir)) != NULL) {
            if (mx_flag_A(all) == 1 && mx_flag_a_f(all) == 0) {
                if (mx_strcmp(entry->d_name, ".") != 0 
                    && mx_strcmp(entry->d_name, "..") != 0)
                        mass[p++] = mx_helper_wh(arrd[i], entry->d_name, all);
            }
            else if (mx_flag_a_f(all) == 1 || entry->d_name[0] != '.')
                mass[p++] = mx_helper_wh(arrd[i], entry->d_name, all);
        }
        mx_sort_flags(mass, p, all, arrd[i]);
        mx_output(mass, p);
        closedir(dir);
    }
}

static int if_R(t_argv *all) {
    for (int i = 0; i < all->k_f; i++)
        if (all->flag[i] == 'R')
            return 1;
    return 0;
}

void mx_out_d_f(char **arrf, char **arrd, t_argv *all) {
    char **mass = NULL;

    mx_output(arrf, len_of_arr(arrf));
    if (arrf[0] != NULL && if_R(all) != 1)
        mx_printchar('\n');
    for (int i = 0; i < len_of_arr(arrd); i++) {
        errno = 0;
        mx_printstr(arrd[i]);
        mx_printstr(":\n");
        mass = mx_creating_array(arrd[i], all, 0);
        entry_in(i, mass, all, arrd);
        if (i + 1 != len_of_arr(arrd))
            mx_printchar('\n');
        if (mass != NULL)
            mx_del_strarr(&mass);
    }
}
