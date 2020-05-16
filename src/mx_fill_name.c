#include "../inc/uls.h"

static void bubble_sort(char **arr, int size) {
    char *buff;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 1; j++)
            if (mx_strcmp(arr[j], arr[j + 1]) > 0) {
                buff = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = buff;
            }
}

static void err_p(char **err, int k, t_argv *all) {
    err[k] = NULL;
    bubble_sort(err, k); //сортируем ошибки
    for (k = 0; err[k]; k++) { //вывод ошибок
        mx_printerr("uls: ");
        mx_printerr(err[k]);
        mx_printerr(": No such file or directory\n");
    }
    if (k != 0)
        all->err = 1;
    mx_del_strarr(&err);
}

void mx_fill_name(char *argv[], t_argv *all, int i) {
    int count = 0;
    char **err = NULL;
    int k = i;
    struct stat sb;

    for (; argv[k]; k++) {} //считаем количество файлов или директорий
    err = (char **)malloc(sizeof(char *) * k); //память под ошибки
    all->name = (char **)malloc(sizeof(char *) * k);
    for (k = 0; argv[i]; i++) {
        if (stat(argv[i], &sb) != -1)// проверяем все элементы
                all->name[count++] = mx_strdup(argv[i]);
        else// значит, что не такого файла или дир
            err[k++] = mx_strdup(argv[i]);
    }
    all->name[count] = NULL;
    err_p(err, k, all); // выводим ошибки
    all->k_n = count; // количество файлов и директорий
}
