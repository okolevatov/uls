#include "../inc/uls.h"

static void if_gr(t_flag_l *l, int gid, int size, int j) {
    int k;

    for (k = 0; (k + mx_numlen(gid) + size) != l->max_group + j; k++)
        mx_printchar(' ');
}

static void else_gr(t_flag_l *l, struct group *gr, int size, int j) {
    int str;
    int k;

    str = mx_strlen(gr->gr_name);
    for (k = 0; (k + str + size) != l->max_group + j; k++)
        mx_printchar(' ');
}

void mx_file_group(t_flag_l *l, int gid, int size) {
    struct group *gr;
    int j = l->max_size;

    if (l->dop_flag[2] != 'o') {
        if (l->dop_flag[0] != 'g')
            mx_printstr("  ");
        if (l->dop_flag[1] == 'n' || !(gr = getgrgid(gid))) {
            mx_printint(gid);
            if_gr(l, gid, size, j);
        }
        else {
            mx_printstr(gr->gr_name);
            else_gr(l, gr, size, j);
        }
    }
    else
        for (int k = 0; (k + size) != j; k++)
            mx_printchar(' ');
    mx_printstr("  ");
}
