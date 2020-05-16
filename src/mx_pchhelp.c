#include "../inc/uls.h"

static t_argv *creating_struct(t_argv *all, char *arrcopy) {
    t_argv *d = (t_argv *)malloc(sizeof(t_argv));

    d->name = (char **)malloc(sizeof(char *) * 1);
    d->name[0] = mx_strdup(arrcopy);
    d->k_n = 1;
    d->k_f = all->k_f;
    d->flag = mx_strdup(all->flag);
    return d;
}

void mx_pchhelp(t_argv *all, char *path, char **mass1) {
    t_argv *copy = NULL;

    if (mx_permcheck(path, all) == 0) {
        copy = creating_struct(all, path); // под аудитор подогнать 
        mx_flagR(copy, path, mass1);
        free(copy->name[0]);
        free(copy->name);
        free(copy->flag);
        free(copy);
    }
}
