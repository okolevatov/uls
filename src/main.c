#include "../inc/uls.h"

static int if_R(t_argv *all) {
    for (int i = 0; i < all->k_f; i++)
        if (all->flag[i] == 'R')
            return 1;
    return 0;
}

int main(int argc, char *argv[]) {
    t_argv *all = (t_argv *)malloc(sizeof(t_argv));
    char *namedir = NULL;

    all->err = 0;
    argc = 0;
    mx_fill_flag(argv, all);
    mx_flag_d(all);
    if (all->name[0])
        namedir = mx_strdup(all->name[0]);
    if (if_R(all) == 1)
        mx_flagR(all, namedir, all->name);
    else
        mx_last_out(all);
    free(namedir);
    // system("leaks -q uls");
    return all->err;
}
