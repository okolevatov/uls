#include "../inc/uls.h"

static void resets_to_zero(t_flag_l *l) {
    l->max_ln = 0;
    l->max_owner = 0;
    l->max_group = 0;
    l->max_size = 0;    
}

void mx_max_all(t_flag_l *l, char **name) {
    struct stat sb;
    char *no;
    int k;

    resets_to_zero(l);
    for (int j = 0; name[j] != NULL; j++) {
        l->path = mx_make_path(name[j], (no = mx_mem_my(name[j], '/')), 0, 0);
        lstat(l->path, &sb);
        if (l->max_ln < (k = mx_numlen(sb.st_nlink)))
            l->max_ln = k;
        if (l->max_owner < (k = mx_find_max_s(l->path, l->dop_flag[1])))
            l->max_owner = k;
        if (l->max_group < (k = mx_find_max_gf(l->path, l->dop_flag[1])))
            l->max_group = k;
        if (l->max_size < (k = mx_numlen(sb.st_size)))
            l->max_size = k;
        mx_strdel(&l->path);
    }
}
