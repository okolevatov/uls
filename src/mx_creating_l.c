#include "../inc/uls.h"

static int auditor(char *arr, t_argv *all, int k) {
    DIR *dir;
    struct dirent *entry;
    int i = 0;

    dir = opendir(arr);
    if (mx_error_13(k, arr, all) == 0)
        return -1;
    while ((entry = readdir(dir)) != NULL) {
        if (mx_flag_A(all) == 1 && mx_flag_a_f(all) == 0) {
            if (mx_strcmp(entry->d_name, ".") != 0 
                && mx_strcmp(entry->d_name, "..") != 0)
                    i++;
        }
        else if (mx_flag_a_f(all) == 1)
            i++;
        else if (entry->d_name[0] != '.')
            i++;
    }
    closedir(dir);
    return i;
}

char **mx_creating_l(char *arr, t_argv *all, int k) {
    char **mass = NULL;
    errno = 0;
    int i = auditor(arr, all, k);

    if (i != -1) {
        mass = (char **)malloc(sizeof(char *) * (i + 1));
        for (int j = 0; j < i + 1; j++)
            mass[j] = NULL;
        return mass;
    }
    return NULL;
}
