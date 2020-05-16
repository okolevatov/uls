#include "../inc/uls.h"

int mx_fd_m(int kol, char **mass) {
    int flag = 0;
    int countf = 0;
    int countd = 0;

    for (int j = 0; j < kol; j++) {
        if (mx_isfile(mass[j]) == 0) 
            countf++;
        if (mx_isfile(mass[j]) == 1)
            countd++;
        if (countf > 0 && countd > 0)
            flag = 1;
    }
    return flag;
}
