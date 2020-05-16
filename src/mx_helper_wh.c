#include "../inc/uls.h"

char *mx_helper_wh(char *name, char *dname, t_argv *all) {
    char *mass = NULL;

    mass = mx_strdup(dname);
    mx_flag_p(mass, name, all);
    return mass;
}
