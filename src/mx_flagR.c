#include "../inc/uls.h"

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
        if (entry->d_name[0] != '.')
            mass1[i++] = mx_strdup(entry->d_name);  
    }
    closedir(dir);
    mx_sort_flags(mass1, i, all, namedir);
    outfingidng(namedir, all, mass1, i);
    mx_del_strarr(&mass1);
}

void mx_flagR(t_argv *all, char *namedir, char **mass) {
    if (all->k_n == 1) {
        if (mx_iflinkl(all, mass[0]) == 1) {}
        else {
            mx_last_out(all);
            finding(all, namedir);
        }
    }
    else {
        mx_sort_flags(mass, all->k_n, all, NULL);
        mx_helpR(mass, all);
    }
}
