#include "../inc/uls.h"

static void files(char **mass, int kol) {
    int j = 0;
    int dirr = 0;

    for (int i = 0; i < kol; i++) { 
        if (mx_isfile(mass[i]) == 0)
            dirr++;
        if (mx_isfile(mass[i]) == 1) {
            mx_printstr(mass[i]);
            mx_printchar('\n');
            j++;
        }
        if (i + 1 >= kol && j > 0 && dirr > 0) {
            mx_printchar('\n');
        }
    }
}

static char **directories(char **mass, int kol) {
    int count = 0;
    char **mass1 = NULL;
    int i;
    int j = 0;

    for (i = 0; i < kol; i++) {
        if (mx_isfile(mass[i]) == 0 || mx_isfile(mass[i]) == -2) {
            count++;
        }
    }
    mass1 = (char **) malloc (sizeof (char *) * (count + 1));
    for (i = 0; i < kol; i++) {
        if (mx_isfile(mass[i]) == 0 || mx_isfile(mass[i]) == -2) {
            mass1[j] = mx_strdup(mass[i]);
            j++;
        } 
    }
    mass1[j] = NULL;
    return mass1;
}

static void out(char *any, t_argv *all, int i) {
    DIR *dir;
    struct dirent *entry;
    char **mass = mx_creating_array(any, all, 0);

    dir = opendir(any);
    if (mx_error_13(all->k_n, any, all)) {
        while ((entry = readdir(dir)) != NULL)
            if (mx_flag_A(all) == 1 && mx_flag_a_f(all) == 0) {
                if (mx_strcmp(entry->d_name, ".") != 0 
                    && mx_strcmp(entry->d_name, "..") != 0)
                    mass[i++] = mx_helper_wh(any, entry->d_name, all);
            }
            else if (mx_flag_a_f(all) == 1 || entry->d_name[0] != '.')
                mass[i++] = mx_helper_wh(any, entry->d_name, all);
        mx_sort_flags(mass, i, all, any);
        for (int j = 0; j < i; j++) {
            mx_printstr(mass[j]);
            mx_printchar('\n');
        }
        mx_del_strarr(&mass);
        closedir(dir);
    }
}

static void out_dir(char **mass, int kol, t_argv *all) {
    char **arr = directories(mass, kol);
    int i = 0;

    while (arr[i] != NULL) {
        if (kol != 1) { 
            mx_printstr(arr[i]);
            mx_printstr(":\n");
        }
        errno = 0;
        out(arr[i], all, 0);
        if (arr[i + 1] != NULL) {
            mx_printchar('\n');
        }
        i++;
    }
    mx_del_strarr(&arr);
}

void mx_flag_1(char **mass, int kol, t_argv *all) {
    mx_sort_flags(mass, kol, all, NULL);
    files(mass, kol);
    out_dir(mass, kol, all);
}
