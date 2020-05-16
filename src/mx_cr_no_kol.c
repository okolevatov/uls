#include "../inc/uls.h"

static void helper(char *name, char **mass, t_argv *all) {
    DIR *dir;
    struct dirent *entry;
    int j = 0;

    dir = opendir(name);
    while ((entry = readdir(dir)) != NULL)
        if (mx_flag_A(all) == 1 && mx_flag_a_f(all) == 0) {
            if (mx_strcmp(entry->d_name, ".") != 0 
                && mx_strcmp(entry->d_name, "..") != 0) {
                    mass[j] = mx_strdup(entry->d_name);
                    mx_flag_p(mass[j], name, all);
                    j++;
            }
        }
        else if (mx_flag_a_f(all) == 1 || entry->d_name[0] != '.') {
            mass[j] = mx_strdup(entry->d_name);
            mx_flag_p(mass[j], name, all);
            j++;
        }
    closedir(dir);
}

char **mx_cr_no_kol(char *name, t_argv *all, int count) {
    DIR *dir;
    struct dirent *entry;
    char **mass1 = NULL;

    dir = opendir(name);
    if (mx_error_13(1, name, all)) {
        while ((entry = readdir(dir)) != NULL)
            if (mx_flag_A(all) == 1 && mx_flag_a_f(all) == 0) {
                if (mx_strcmp(entry->d_name, ".") != 0 
                    && mx_strcmp(entry->d_name, "..") != 0)
                        count++;
            }
            else if (mx_flag_a_f(all) == 1 || entry->d_name[0] != '.')
                count++;
        closedir(dir);
        mass1 = (char **) malloc (sizeof (char *) * (count + 1));
        helper(name, mass1, all);
        mass1[count] = NULL;
    }
    return mass1;
}
