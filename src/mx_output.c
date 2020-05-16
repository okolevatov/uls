#include "../inc/uls.h"

static int longest_word(char **mass, int i) {
    int len = 0;
    int buff;

    for (int j = 0; j < i; j++) {
        buff = mx_strlen(mass[j]);
        if (buff > len)
            len = buff;
    }
    return len; 
}

static int cl_word(char **mass, int i) {
    int max_len = longest_word(mass, i);

    if (max_len % 8 == 0)
        max_len++;
    while (max_len % 8 != 0) 
        max_len++;
    return max_len;
}

static int if_zero(int k, int i, int w, int c) {
    int level = 1;

    k = w / c;
    if (k <= 1)
        level = i;
    else if ( i % k != 0 && i / k >= 1) 
        level = (i / k) + 1;
    else if ( i % k == 0 && i / k >= 1)
        level = (i / k);
    return level;
}


void mx_output(char **mass, int i) {
    struct winsize w;
    int c = cl_word(mass, i);
    int count_k_g_l[4] = {0, 0, 0, 0};

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    count_k_g_l[3] = if_zero(count_k_g_l[1], i, w.ws_col, c);
    for (int y = 0; y < count_k_g_l[3]; y++) {
        for (int j = count_k_g_l[2]; j < i; j = j + count_k_g_l[3]) {
            count_k_g_l[0] = mx_strlen(mass[j]);
            mx_printstr(mass[j]);
            if (j + count_k_g_l[3] >= i)
                mx_printchar('\n');
            else {
                while (c - count_k_g_l[0] != 0) {
                    mx_printchar(' ');
                    count_k_g_l[0]++;
                } 
            }
        }
        count_k_g_l[2]++;
    }
}
