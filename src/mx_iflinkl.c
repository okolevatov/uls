#include "../inc/uls.h"

static int l_check(t_argv *all) {
    for (int i = 0; i < all->k_f; i++) {
        if (all->flag[i] == 'l')
            return 1;
    }
    return 0;
}

int mx_iflinkl(t_argv *all, char *mass) {
    struct stat buf;

    lstat(mass, &buf);
    if (MX_ISLNK(buf.st_mode) && l_check(all) == 1) {
        mx_last_out(all);
        return 1;
    }
    return 0;
}
