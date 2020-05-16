#include "../inc/uls.h"

static char **ls_check_dir(char *argv[], int argc) {
    int count = 0;
    char **mass = NULL;
    int i;
    int j = 0;

    for (i = 0; i < argc; i++)
        if (mx_isfile(argv[i]) == 0 || mx_isfile(argv[i]) == -2)
            count++;
    mass = (char **) malloc (sizeof (char *) * (count + 1));
    for (i = 0; i < argc; i++)
        if (mx_isfile(argv[i]) == 0 || mx_isfile(argv[i]) == -2) {
            mass[j] = mx_strdup(argv[i]);
            j++;
        }
    mass[j] = NULL;
    return mass;
}

static char **ls_check_file(char *argv[], int argc) {
    int count = 0;
    char **mass = NULL;
    int i;
    int j = 0;

    for (i = 0; i < argc; i++)
        if (mx_isfile(argv[i]) == 1)
            count++;
    mass = (char **) malloc (sizeof (char *) * (count + 1));
    for (i = 0; i < argc; i++)
        if (mx_isfile(argv[i]) == 1) {
            mass[j] = mx_strdup(argv[i]);
            j++;
        } 
    mass[j] = NULL;
    return mass;
}

static int if_two_check(char *argv) {
    if (mx_isfile(argv) == 1) { 
        mx_printstr(argv); 
        mx_printstr("\n");
        return 1;
    } 
    return 0;
}

static void if_two(char *argv[], t_argv *all) {
    DIR *dir;
    struct dirent *entry;
    int i = 0;
    char **mass = mx_creating_array(argv[0], all, 0);

    dir = opendir(argv[0]);
    if (mx_error_13(all->k_n, argv[0], all)) {
        while ((entry = readdir(dir)) != NULL)
            if (mx_flag_A(all) == 1 && mx_flag_a_f(all) == 0) {
                if (mx_strcmp(entry->d_name, ".") != 0 
                    && mx_strcmp(entry->d_name, "..") != 0)
                    mass[i++] = mx_helper_wh(argv[0], entry->d_name, all);
            }
            else if (mx_flag_a_f(all) == 1 || entry->d_name[0] != '.')
                mass[i++] = mx_helper_wh(argv[0], entry->d_name, all);
        closedir(dir);
        mx_sort_flags(mass, i, all, argv[0]);
        mx_output(mass, i);
        mx_del_strarr(&mass);
    }
}

void mx_main_uls(char *argv[], int argc, t_argv *all) { 
    char **arrf = NULL;
    char **arrd = NULL;

    if (argc > 0) {
        if (argc == 1) {
            if (if_two_check(argv[0]) == 0) {
                errno = 0;
                if_two(argv, all);
            }
        }
        else { 
            mx_sort_flags(argv, argc, all, NULL);
            arrf = ls_check_file(argv, argc);
            arrd = ls_check_dir(argv, argc);
            mx_out_d_f(arrf, arrd, all); //на лики проверку
            mx_del_strarr(&arrf);
            mx_del_strarr(&arrd);
        }
    }
}
