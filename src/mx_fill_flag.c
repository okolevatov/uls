#include "../inc/uls.h"

static int no_flag(char c) {
    if (c != 'l' && c != 'm' && c != 'R' && c != 'A' && c != 'f' && c != 'd'
        && c != 'S' && c != 'a' && c != 'r' && c != '1'
        && c != 'o' && c != 'p' && c != 'n' && c != 't'
        && c != 'g' && c != 'T' && c != 'C')
        return 1;
    return 0;
}

static void illegal(char c) {
    mx_printerr("uls: illegal option -- ");
    mx_printerr_c(c);
    mx_printerr_c(10);
    mx_printerr("usage: uls [-ACRSTadfglmnoprt1] [file ...]"); //here 
    mx_printerr_c(10);
    exit(1);
}

static int count_flags(char *argv[]) {
    int k = 0;

    if (!argv && argv[1][0] != '-')
        return k;
    for (int j = 1; argv[j] && argv[j][0] == '-'; j++)
        for (int i = 1; argv[j][i] && argv[j][i] != argv[j][i - 1]; i++)
            if (!no_flag(argv[j][i]))
                k++;
            else
                illegal(argv[j][i]);
    return k;
}

void mx_fill_flag(char *argv[], t_argv *all) {
    int k = count_flags(argv);
    int counter = 0;
    int j = 1;

    all->k_f = k;
    if (k > 0) {
        all->flag = (char *)malloc(sizeof(char) * k);
        for (; argv[j] && argv[j][0] == '-'; j++)
            for (int i = 1; argv[j][i]; i++)
                if (argv[j][i] != argv[j][i - 1])
                    all->flag[counter++] = argv[j][i];
    }
    if (argv[j])
        mx_fill_name(argv, all, j);
    else {
        all->name = (char **)malloc(sizeof(char *) * 2);
        all->name[0] = ".";
        all->name[1] = NULL;
        all->k_n = 1;
    }
}
