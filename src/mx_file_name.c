#include "../inc/uls.h"

void mx_file_name(char *name, t_flag_l *l, int mode, int size) {
    if (MX_ISLNK(mode)) {
        char *buff = (char *)malloc(sizeof(char) * size + 1);

        mx_printchar(' ');
        mx_printstr(name);
        mx_printstr(" -> ");
        readlink(l->path, buff, size + 1);
        for (int i = 0; buff[i]; i++)
            mx_printchar(buff[i]);
        mx_strdel(&buff);
    }
    else {
        mx_printchar(' ');
        mx_printstr(name);
    }
}
