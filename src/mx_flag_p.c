#include "../inc/uls.h"

static int is_flag(t_argv *all) {
    for (int i = 0; i < all->k_f; i++) {
        if (all->flag[i] == 'p') {
            return 1;
        }
    }
    return 0;
}

void mx_flag_p(char *mass, char *namedir, t_argv *all) {
    int yes = is_flag(all);

    if (yes == 1) {
        if (namedir[0] != '/')
            namedir = mx_strdup(".");
        char *name = mx_strjoin(namedir, "/");
        char *path = mx_strjoin(name, mass);
        char *temp = mx_strdup(mass);

        if (mx_isfile(path) == 0) {
            free(mass);
            mass = mx_strjoin(temp, "/");
        }
        free(temp);
        free(name);
        free(path);
        //free(namedir);
    }
}
