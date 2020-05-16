#include "../inc/uls.h"

static char **check_file(char **mass, int kol) {
    int count = 0;
    char **mass1 = NULL;
    int j = 0;

    for (int i = 0; i < kol; i++) {
        if (mx_isfile(mass[i]) == 1) {
            count++;
        }
    }
    mass1 = (char **) malloc (sizeof (char *) * (count + 1));
    for (int i = 0; i < kol; i++) {
        if (mx_isfile(mass[i]) == 1) {
            mass1[j] = mx_strdup(mass[i]);
            j++;
        }
    }
    mass1[j] = NULL;
    return mass1;
}

static char **helper_dir(char **mass, int kol) {
    int count = 0;
    char **mass1 = NULL;
    int i;
    int j = 0;

    for (i = 0; i < kol; i++) {
        if (mx_isfile(mass[i]) == 0) {
            count++;
        } 
    }
    mass1 = (char **) malloc (sizeof (char *) * (count + 1));
    for (i = 0; i < kol; i++) {
        if (mx_isfile(mass[i]) == 0) {
            mass1[j] = mx_strdup(mass[i]);
            j++;
        } 
    }
    mass1[j] = NULL;
    return mass1;
}

static char **indir(char *name, t_argv *all) {
    char **mass2 = NULL;
    int i = 0;

    errno = 0;
    mass2 = mx_cr_no_kol(name, all, 0);
    if (mass2 != NULL) {
        while (mass2[i] != NULL)
            i++;
        mx_sort_flags(mass2, i, all, name);
    }
    return mass2;
}

static void print_dir(char **mass, int kol, t_argv *all) {
    char **arr = helper_dir(mass, kol);
    char **array = NULL;
    int i = 0;

    while (arr[i] != NULL) {
        mx_printstr(arr[i]);
        mx_printstr(":\n");
        array = indir(arr[i], all);
        if (array != NULL) {
            mx_output_m(array, 0, 0);
            mx_del_strarr(&array);
            mx_printchar('\n');
        }
        if (arr[i + 1] != NULL) 
            mx_printstr("\n");
        i++;
    }
    mx_del_strarr(&arr);
}

void mx_flag_m(char **mass, int kol, t_argv *all) { //struct 
    char **arr = NULL;
    int flag = mx_fd_m(kol, mass);

    if (kol > 1) {
        mx_sort_flags(mass, kol, all, NULL);
        arr = check_file(mass, kol);
        mx_output_m(arr, flag, 0); // зафришить надо  
        if (arr[0] != NULL)
            mx_printchar('\n');
        for (int i = 0; i < kol; i++) {
            if ((mx_isfile(mass[i]) == 0) && arr[0] != NULL) {
                mx_printchar('\n');
                break ;
            }
        }
        print_dir(mass, kol, all);
        mx_del_strarr(&arr);
    } 
    else if (kol == 1)
        mx_one_m(mass, all);
}
