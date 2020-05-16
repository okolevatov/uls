#include "../inc/uls.h"

static void file_type(int mode) {
    if (MX_ISREG(mode))
        mx_printchar('-');
    else if (MX_ISDIR(mode))
        mx_printchar('d');
    else if (MX_ISBLK(mode))
        mx_printchar('b');
    else if (MX_ISCHR(mode))
        mx_printchar('c');
    else if (MX_ISFIFO(mode))
        mx_printchar('p');
    else if (MX_ISLNK(mode))
        mx_printchar('l');
    else if (MX_ISSOCK(mode))
        mx_printchar('s');
    else
        mx_printchar('?');
}

static void file_perm(int mode) {
    (mode & MX_IRUSR) ? mx_printchar('r') : mx_printchar('-');
    (mode & MX_IWUSR) ? mx_printchar('w') : mx_printchar('-');
    if (mode & MX_ISUID)
        (mode & MX_IXUSR) ? mx_printchar('s') : mx_printchar('S');
    else
        (mode & MX_IXUSR) ? mx_printchar('x') : mx_printchar('-');
    (mode & MX_IRGRP) ? mx_printchar('r') : mx_printchar('-');
    (mode & MX_IWGRP) ? mx_printchar('w') : mx_printchar('-');
    if (mode & MX_ISGID)
        (mode & MX_IXGRP) ? mx_printchar('s') : mx_printchar('l');
    else
        (mode & MX_IXGRP) ? mx_printchar('x') : mx_printchar('-');
    (mode & MX_IROTH) ? mx_printchar('r') : mx_printchar('-');
    (mode & MX_IWOTH) ? mx_printchar('w') : mx_printchar('-');
    if (mode & MX_ISVTX)
        (mode & MX_IXOTH) ? mx_printchar('t') : mx_printchar('T');
    else
        (mode & MX_IXOTH) ? mx_printchar('x') : mx_printchar('-');
}

static void dog_plus(const char *path) {
    acl_t acl = NULL;
    ssize_t xattr = 0;

    acl = acl_get_file(path, 256);
    xattr = listxattr(path, NULL, 0, MX_HWOKNOWS);
    if (xattr > 0)
        mx_printchar('@');
    else if (acl != NULL)
        mx_printchar('+');
    else
        mx_printchar(' ');
    acl_free(acl);
    acl = NULL;
    return ;
}

void mx_file_perm(char *name, int mode) {
    file_type(mode);
    file_perm(mode);
    dog_plus(name);
}
