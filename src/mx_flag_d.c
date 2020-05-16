#include "../inc/uls.h"

static int is_d(t_argv *all) {
    int is_d = 0;

    for (int i = 0; i < all->k_f; i++) {
        if (all->flag[i] == 'd') {
            is_d = 1;
        }
    }
    return is_d;
}

static int flag_1(t_argv *all) {
    int count = 1;

    for (int i = 0; i < all->k_n; i++) {
        mx_flag_p(all->name[i], NULL, all);
        mx_printstr(all->name[i]);
        mx_printchar('\n'); 
    }
    return count;
}

static int flag_m(t_argv *all) {
    int count = 1;

    for (int i = 0; i < all->k_n; i++) {
        mx_flag_p(all->name[i], NULL, all);
        mx_output_m(all->name, 0, 0);
        mx_printchar('\n');
    }
    return count;
}

static void help(t_argv *all, int count) {
    if (count == 0) {
        for (int i = 0; i < all->k_n; i++)
            mx_flag_p(all->name[i], NULL, all);
        mx_output(all->name, all->k_n);
    }
}

void mx_flag_d(t_argv *all) {
    int count = 0;
    
    if (is_d(all) == 1) {
        mx_sort_flags(all->name, all->k_n, all, NULL);
        for (int i = all->k_f - 1; i >= 0; i--) {
            if (all->flag[i] == 'm') 
                count = flag_m(all);
            else if (all->flag[i] == '1')
                count = flag_1(all);
            else if (all->flag[i] == 'l') {
                mx_flag_l(all->name, all->k_n, all); 
                count++;
            }
            if (count != 0)
                break ;
        }
        help(all, count);
        exit(all->err);
    }
}
