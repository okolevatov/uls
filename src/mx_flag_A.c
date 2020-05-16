#include "../inc/uls.h"

int mx_flag_A(t_argv *all) {
    for (int i = 0; i < all->k_f; i++)
        if (all->flag[i] == 'A')
            return 1;
    return 0;
}
