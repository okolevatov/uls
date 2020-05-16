#include "../inc/uls.h"

char **mx_creating_array(char *arr, t_argv *all, int count) {
    DIR *dir;
    struct dirent *entry;
    char **mass = NULL;
    
    dir = opendir(arr);
    if (!dir)
        return NULL;
    while ((entry = readdir(dir)) != NULL)
        if (mx_flag_A(all) == 1 && mx_flag_a_f(all) == 0) {
            if (mx_strcmp(entry->d_name, ".") != 0 
                && mx_strcmp(entry->d_name, "..") != 0)
                    count++;
        }
        else if (mx_flag_a_f(all) == 1 || entry->d_name[0] != '.')
            count++;
    mass = (char **)malloc(sizeof(char *) * (count + 1));
    for (int j = 0; j < count + 1; j++) 
        mass[j] = NULL;
    closedir(dir);
    return mass;
}
