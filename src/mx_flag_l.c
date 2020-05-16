#include "../inc/uls.h"
static void loop_if_dir(t_flag_l *l, char *name, char **mass) {
    struct stat sb;

    for (int j = 0; mass[j] != NULL; j++) {
        l->path = mx_make_path(mass[j], name, 0, 0);
        lstat(l->path, &sb);
        mx_file_perm(l->path, sb.st_mode);
        mx_num_hard(l->max_ln, sb.st_nlink);
        if (l->dop_flag[0] == 'x')
            mx_file_owner(l->dop_flag[1], l->max_owner, sb.st_uid);
        mx_file_group(l, sb.st_gid, mx_numlen(sb.st_size));
        mx_file_size(sb.st_mode, sb.st_rdev, sb.st_size);
        mx_mod_time(sb.st_mtime, l->dop_flag[3]);
        mx_file_name(mass[j], l, sb.st_mode, 256);
        mx_printchar(10);
        mx_strdel(&l->path);
    }
}

void mx_if_dir(char *name, int k, t_flag_l *l, t_argv *all) {
    char **mass;
    int kol;

    mass = mx_creating_l(name, all, k);
    if (mass != NULL) {
        if (k != 1) {
            mx_printstr(name);
            mx_printstr(":\n");
        }
        mx_creating_array_lena(mass, name, all, 0);
        kol = mx_count_arr(mass);
        mx_sort_flags(mass, kol, all, name);
        mx_total(mass, name);
        l->max_ln = mx_find_max_n(mass, name);
        l->max_owner = mx_find_max_se(mass, name, l->dop_flag[1]);
        l->max_group = mx_find_max_g(mass, name, l->dop_flag[1]);
        l->max_size = mx_find_max_z(mass, name);
        loop_if_dir(l, name, mass);
        mx_del_strarr(&mass);
    }
}

static int if_R(t_argv *all) {
    for (int i = 0; i < all->k_f; i++)
        if (all->flag[i] == 'R')
            return 1;
    return 0;
}

void mx_flag_l(char **name, int k, t_argv *all) {
    t_flag_l *l = (t_flag_l *)malloc(sizeof(t_flag_l));
    struct stat sb;
    char **files;

    mx_sort_flags(name, k, all, NULL); //NULL or "." ?
    l->dop_flag = mx_check_dop_l(all->flag);
    files = mx_find_all(name, all->k_n);
    mx_if_file_l(files, l, all);
    for (int i = 0; i < k; i++) {
        lstat(name[i], &sb);
        if (MX_ISDIR(sb.st_mode) && l->dop_flag[4] == 'x') {
            if (!if_R(all) && i != 0)
                mx_printchar(10);
            mx_if_dir(name[i], k, l, all);
        }
    }
    mx_strdel(&l->dop_flag);
    free(l);
    mx_del_strarr(&files);
}
