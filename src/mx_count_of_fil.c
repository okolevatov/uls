#include "../inc/uls.h"

static int l_check(t_argv *all) {
    for (int i = 0; i < all->k_f; i++) {
        if (all->flag[i] == 'l')
            return 1;
    }
    return 0;
}

static char **massiv(int count, char **mass, int k) {
    char **massiv = (char **)malloc(sizeof(char *) * (count + 1));
    int j = 0;
    struct stat buf;

    for (int i = 0; mass[i] != NULL; i++) {
        lstat(mass[i], &buf);
        if (mx_isfile(mass[i]) == 1
            || (MX_ISLNK(buf.st_mode) && k == 1)) {
            massiv[j] = mx_strdup(mass[i]);
            j++;
        }
    }
    massiv[count] = NULL;
    return massiv;
}

static t_argv *creating_struct(t_argv *all, int count) {
    t_argv *d = (t_argv *)malloc(sizeof(t_argv));

    d->name = (char **)malloc(sizeof(char *) * count + 1);
    d->k_n = count;
    d->k_f = all->k_f;
    d->flag = mx_strdup(all->flag);
    return d;
}

static void wet(int count, t_argv *all, char **mass) {
    char **arrf = NULL;
    t_argv *a = creating_struct(all, count);

    arrf = massiv(count, mass, l_check(all));
    for (int i = 0; i < count; i++)
        a->name[i] = mx_strdup(arrf[i]);
    a->name[count] = NULL;
    mx_last_out(a);
    mx_del_strarr(&a->name);
    free(a->flag);
    mx_del_strarr(&arrf);
    free(a);
}

int mx_count_of_fil(char **mass, t_argv *all) {
    int count = 0;
    struct stat buf;

    for (int i = 0; mass[i] != NULL; i++) {
        lstat(mass[i], &buf);
        if (mx_isfile(mass[i]) == 1
            || (MX_ISLNK(buf.st_mode) && l_check(all) == 1))
            count++;
    }
    if (count > 0) {
        wet(count, all, mass);
        return count;
    }
    return 0;
}
