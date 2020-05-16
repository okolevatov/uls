#include "../inc/uls.h"

int mx_flag_a_f(t_argv *all) {
    for (int i = 0; i < all->k_f; i++)
        if (all->flag[i] == 'a' || all->flag[i] == 'f')
            return 1;
    return 0;
}
