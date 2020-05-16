#include "../inc/uls.h"

static void flag_r(t_argv *all, int kol, char **mass, int f_flag){
    if (f_flag != 1) {
        for (int j = 0; j < all->k_f; j++) {
            if (all->flag[j] == 'r') {
                mx_flag_r(mass, kol);
                break ;
            }  
        }
    }
}

static int flag_f(t_argv *all) {
    int f_flag = 0;
    for (int j = 0; j < all->k_f; j++) {
        if (all->flag[j] == 'f') {
            f_flag++;
            break ;
        }  
    }
    return f_flag;
}

void mx_sort_flags(char **mass, int kol, t_argv *all, char *namedir) { 
    int count = 0;
    int f_flag = 0;
    
    f_flag = flag_f(all);
    if (f_flag == 0) {
        for (int i = 0; i < all->k_f; i++) {
            if (all->flag[i] == 'S') {
                mx_flag_S(mass, kol, namedir);
                count++;
                break ;
            }
            else if (all->flag[i] == 't') {
                mx_flag_t(mass, kol, namedir);
                count++;
            }
        }
        if (count == 0) 
            mx_bubble_sort(mass, kol);
        flag_r(all, kol, mass, f_flag);
    }
}
