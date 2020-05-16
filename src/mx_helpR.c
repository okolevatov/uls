#include "../inc/uls.h"

static t_argv *creating_struct(t_argv *all, char *arrcopy) {
    t_argv *d = (t_argv *)malloc(sizeof(t_argv));

    d->name = (char **)malloc(sizeof(char *) * 1);
    d->name[0] = mx_strdup(arrcopy);
    d->k_n = 1;
    d->k_f = all->k_f;
    d->flag = mx_strdup(all->flag);

    return d;
}

static int l_check(char *mass, t_argv *all) {
    struct stat buf;
    int l_ch = 0;

    lstat(mass, &buf);
    for (int i = 0; i < all->k_f; i++)
        if (all->flag[i] == 'l')
            l_ch++;
    if (MX_ISLNK(buf.st_mode) && l_ch == 1) {
        return 1;
    }
    return 0;
}

static void outfingidng(char *namedir, t_argv *all, char **mass1, int i) {
    for (int j = 0; j < i; j++) { // тут рекурсия 
        char *name = mx_strjoin(namedir, "/");
        char *path = mx_strjoin(name, mass1[j]);

        if (mx_isfileR(path) == 0) { 
            mx_printchar('\n');
            if (path[0] == '/' && path[1] == '/')
                mx_printstr(&path[1]);
            else
                mx_printstr(path);
            mx_printstr(":\n");
            mx_pchhelp(all, path, mass1);
        }
        free(name);
        free(path);
    }
}

static void finding(t_argv *all, char *namedir) {
    DIR *dir;
    struct dirent *entry;
    char **mass1 = mx_creating_array(namedir, all, 0);
    int i = 0;

    dir = opendir(namedir);
    if (!dir)
        return ;
    while ((entry = readdir(dir)) != NULL) {
            if (entry->d_name[0] != '.') {
            mass1[i++] = mx_strdup(entry->d_name);
        }  //Тут создаем матрицу, точнее переносим все в нее
    }
    closedir(dir);
    mx_sort_flags(mass1, i, all, namedir);
    outfingidng(namedir, all, mass1, i);
    mx_del_strarr(&mass1);
}

void mx_helpR(char **mass, t_argv *all) {
    int fil_flag = mx_count_of_fil(mass, all);

    for (int i = 0; i < all->k_n; i++) {
        if (mx_isfile(mass[i]) == 0 && l_check(mass[i], all) == 0) {
            t_argv *v = creating_struct(all, mass[i]);
            if (fil_flag >= 1)
                mx_printchar('\n');
            if (fil_flag == 0 && i != 0)
                mx_printchar('\n');
            fil_flag = 0;
            mx_printstr(mass[i]);
            mx_printstr(":\n");
            mx_last_out(v);
            finding(v, mass[i]);
            free(v->name[0]);
            free(v->name);
            free(v->flag);
            free(v);
        }
    }
}
