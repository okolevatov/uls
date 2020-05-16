#include "../inc/uls.h"

static int flag_C(t_argv *all) {
    for (int i = 0; i < all->k_f; i++) {
        if (all->flag[i] == 'C') {
            return 1;
        }
    }
    return 0;
}

static void is_att(t_argv *all) {
    if (isatty(1) == 0) {
        if (flag_C(all) == 1)
            mx_main_uls(all->name, all->k_n, all);
        else 
            mx_flag_1(all->name, all->k_n, all);
    }
    else
        mx_main_uls(all->name, all->k_n, all);
}

void mx_last_out(t_argv *all) { 
    for (int i = all->k_f - 1; i >= 0; i--) {
        if (all->flag[i] == 'l' || all->flag[i] == 'n'
            || all->flag[i] == 'g' || all->flag[i] == 'o') {
            mx_flag_l(all->name, all->k_n, all);
            return ;
        }
        else if (all->flag[i] == '1') {
            mx_flag_1(all->name, all->k_n, all);
            return ;
        }
        else if (all->flag[i] == 'm') {
            mx_flag_m(all->name, all->k_n, all);
            return ;
        }
        else if (all->flag[i] == 'C') {
            mx_main_uls(all->name, all->k_n, all);
            return ;
        }
    }
    is_att(all);
}
