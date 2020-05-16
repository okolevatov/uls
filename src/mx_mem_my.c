#include "../inc/uls.h"

char *mx_mem_my(char *s, int c) {
    struct stat sb;
    
    lstat(s, &sb);
    if (s[0] == c) {
        if (MX_ISDIR(sb.st_mode))
            return NULL;
        else
            return "/";
    }
    return ".";
}
