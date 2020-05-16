#include "../inc/uls.h"

void mx_creating_array_lena(char **mass, char *name, t_argv *all, int i) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(name);
    while ((entry = readdir(dir)) != NULL)
        if (mx_flag_A(all) == 1 && mx_flag_a_f(all) == 0) {
            if (mx_strcmp(entry->d_name, ".") != 0
                && mx_strcmp(entry->d_name, "..") != 0) {
                    mass[i] = mx_strdup(entry->d_name);
                    mx_flag_p(mass[i], name, all);
                    i++;
            }
        }
        else if (mx_flag_a_f(all) == 1 || entry->d_name[0] != '.') {
            mass[i] = mx_strdup(entry->d_name);
            mx_flag_p(mass[i], name, all);
            i++;
        }
    mass[i] = NULL;
    closedir(dir);
}
