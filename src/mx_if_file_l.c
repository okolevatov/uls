#include "../inc/uls.h"

static void enter(char **name, t_argv *all) {
    if (mx_count_arr(name) != 0 && all->k_n - mx_count_arr(name) != 0)
        mx_printchar(10);
}

void mx_if_file_l(char **name, t_flag_l *l, t_argv *all) {
    struct stat sb;
    char *no;

    mx_max_all(l, name);
    for (int j = 0; name[j] != NULL; j++) {
        l->path = mx_make_path(name[j], (no = mx_mem_my(name[j], '/')), 0, 0);
        lstat(l->path, &sb);
        mx_file_perm(l->path, sb.st_mode);
        mx_num_hard(l->max_ln, sb.st_nlink);
        if (l->dop_flag[0] == 'x')
            mx_file_owner(l->dop_flag[1], l->max_owner, sb.st_uid);
        mx_file_group(l, sb.st_gid, mx_numlen(sb.st_size));
        mx_file_size(sb.st_mode, sb.st_rdev, sb.st_size);
        mx_mod_time(sb.st_mtime, l->dop_flag[3]);
        mx_file_name(name[j], l, sb.st_mode, 256);
        mx_printchar(10);
        mx_strdel(&l->path);
    }
    enter(name, all);
}
