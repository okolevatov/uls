#include "../inc/uls.h"

void mx_output_m(char **mass, int flag, int len) {
    struct winsize w;
    int all_len = 0;

    ioctl(MX_STDOUT_FILENO, MX_TIOCGWINSZ, &w);
    all_len = w.ws_col;
    for (int i = 0; mass[i] != NULL; i++) {
        len = mx_strlen(mass[i]) + 2;
        if ((all_len = all_len - len) > 0 || (w.ws_col < len)) {
            mx_printstr(mass[i]);
            if (mass[i + 1] != NULL && flag != 1) 
                mx_printstr(", ");
            if (flag == 1)
                mx_printstr(", ");
        }
        else {
            all_len = w.ws_col;
            mx_printchar('\n');
            i--;
        }
    }
}
