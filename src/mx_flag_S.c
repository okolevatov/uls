#include "../inc/uls.h"

static void swap(off_t *arr, int j) {
    off_t temp1;

    temp1 = arr[j + 1];
    arr[j + 1] = arr[j];
    arr[j] = temp1;
}

static void sort(char **mass, int kol, off_t *arr) {
    char *temp = NULL;

    for (int i = 0; i < kol; i++) {
        for (int j = 0; j < kol - 1; j++) {
            if (arr[j] < arr[j + 1] 
                || (arr[j] == arr[j + 1]
                && mx_strcmp(mass[j],mass[j + 1]) > 0)) {
                    temp = mx_strdup(mass[j + 1]);
                    free(mass[j + 1]);
                    mass[j + 1] = mx_strdup(mass[j]);
                    free(mass[j]);
                    mass[j] = mx_strdup(temp);
                    swap(arr, j);
                    free(temp);
            }
        }
    }
}

static char *size_of_word(const char *massel, const char *namedir) {
    int i = mx_strlen(massel);
    int j = mx_strlen(namedir);
    int h = 0;
    int k = 0;
    char *arr = NULL;

    arr = (char*)(malloc)(sizeof(char) * (i + j + 2));
    for (; h < j; h++)
        arr[h] = namedir[h];
    arr[h] = '/';
    h++;
    for (;h < i + j + 1; h++) {
        arr[h] = massel[k];
        k++;
    }
    arr[h] = '\0';
    return arr;
}

static off_t *size_arr(char **mass, int kol, char *namedir) {
    off_t *arr = (off_t*)(malloc)(sizeof(off_t) * (kol));
    struct stat buff;
    int i;
    char *temp = NULL;

    for (i = 0; i < kol; i++) {   
        if (mass[i][0] != '/' && namedir == NULL) { 
            temp = size_of_word(mass[i], ".");
        } else if (namedir == NULL) {
            temp = mx_strdup(mass[i]);
        } else {
            temp = size_of_word(mass[i], namedir);
        }

        lstat(temp, &buff);
        arr[i] = buff.st_size;
        free(temp);
    }
    return arr;
}

void mx_flag_S(char **mass, int kol, char *namedir) {
    off_t *array = size_arr(mass, kol, namedir);
    sort(mass, kol, array);
    free(array);
}
