#ifndef ULS_H
#define ULS_H 

#include <sys/types.h>
#include <sys/ioctl.h>
#include <dirent.h>
#include "../libmx/inc/libmx.h"
#include <sys/stat.h>
#include <unistd.h>

#include <grp.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <errno.h>

#include <string.h>

#define MX_STDOUT_FILENO 1
#define MX_TIOCGWINSZ _IOR('t', 104, struct winsize)
#define MX_IFMT 0170000
#define MX_IFREG 0100000
#define MX_IFDIR 0040000
#define MX_IFBLK 0060000
#define MX_IFCHR 0020000
#define MX_IFIFO 0010000
#define MX_IFLNK 0120000
#define MX_IFSOCK 0140000
#define MX_IRUSR 0000400
#define MX_IWUSR 0000200
#define MX_ISUID 0004000
#define MX_IXUSR 0000100
#define MX_IRGRP 0000040
#define MX_IWGRP 0000020
#define MX_ISGID 0002000
#define MX_IXGRP 0000010
#define MX_IROTH 0000004
#define MX_IWOTH 0000002
#define MX_ISVTX 0001000
#define MX_IXOTH 0000001
#define MX_HWOKNOWS 0x0001
#define MX_ISREG(m) (((m) & MX_IFMT) == MX_IFREG)
#define MX_ISDIR(m) (((m) & MX_IFMT) == MX_IFDIR)
#define MX_ISBLK(m) (((m) & MX_IFMT) == MX_IFBLK)
#define MX_ISCHR(m) (((m) & MX_IFMT) == MX_IFCHR)
#define MX_ISFIFO(m) (((m) & MX_IFMT) == MX_IFIFO)
#define MX_ISLNK(m) (((m) & MX_IFMT) == MX_IFLNK)
#define MX_ISSOCK(m) (((m) & MX_IFMT) == MX_IFSOCK)

typedef struct s_argv {
    char *flag;
    int k_f;
    char **name;
    int k_n;
	int err;
} t_argv;

typedef struct s_flag_l {
	int max_ln;
	int max_owner;
	int max_group;
	int max_size;
	char *path;
	char *dop_flag;
} t_flag_l;

void mx_main_uls(char *argv[], int argc, t_argv *all);
int mx_isfile( char *argv);
char **mx_creating_array(char *arr, t_argv *all, int count);
void mx_output(char **mass, int i);
void mx_sort_args(char *argv[], int argc);
void mx_out_d_f(char **arrf, char **arrd, t_argv *all);
void mx_flag_1(char **mass, int kol, t_argv *all);
void mx_flag_m(char **mass, int kol, t_argv *all);
void mx_output_m(char **mass, int flag, int len);
char **mx_cr_no_kol(char *name, t_argv *all, int count);
void mx_flag_S(char **mass, int kol, char *namedir);
void mx_flag_r(char **mass, int kol);
void mx_fill_flag(char *argv[], t_argv *all);
void mx_printerr(const char *s);
void mx_printerr_c(char s);
void mx_fill_name(char *argv[], t_argv *all, int i);
void mx_flag_l(char **name, int k, t_argv *all);
void mx_sort_flags(char **mass, int kol, t_argv *all, char *namedir);
void mx_flag_t(char **mass, int kol, char *namedir);
void mx_last_out(t_argv *all);
int mx_flag_a_f(t_argv *all);
int mx_flag_A(t_argv *all);
void mx_flag_p(char *mass, char *namedir, t_argv *all);
void mx_flag_d(t_argv *all);
void mx_flagR(t_argv *all, char *namedir, char **mass);
int mx_iflinkl(t_argv *all, char *mass);
char *mx_helper_wh(char *name, char *dname, t_argv *all);
void mx_one_m(char **mass, t_argv *all);
int mx_fd_m(int kol, char **mass);
void mx_helpR(char **mass, t_argv *all);
void mx_pchhelp(t_argv *all, char *path, char **mass1);
// all for flag -l --->
char *mx_make_path(char *massel, char *namedir, int h, int k);
int mx_numlen (int n);
void mx_file_perm(char *name, int mode);
char *mx_dec_to_hex(int dec);
void mx_file_size(int mode, unsigned int rdev, int size);
int mx_find_max_n(char **mass, char *name);
int mx_find_max_z(char **mass, char *name);
char *mx_check_dop_l(char *flag);
int mx_find_max_g(char **mass, char *name, char c);
int mx_find_max_s(char *name, char c);
int mx_find_max_gf(char *path, char c);
int mx_count_arr(char **arr);
char **mx_creating_l(char *arr, t_argv *all, int k);
int mx_error_13(int k, char *arr, t_argv *all);
int mx_find_max_se(char **mass, char *name, char c);
void mx_if_file_l(char **name, t_flag_l *l, t_argv *all);
void mx_max_all(t_flag_l *l, char **name);
void mx_total(char **mass, char *name);
char **mx_find_all(char **name, int k);
char *mx_mem_my(char *s, int c);
void mx_num_hard(int f, int nlink);
void mx_file_owner(char c, char f, int uid);
void mx_file_group(t_flag_l *l, int gid, int size);
void mx_mod_time(time_t mtime, char k);
void mx_file_name(char *name, t_flag_l *l, int mode, int size);
void mx_creating_array_lena(char **mass, char *name, t_argv *all, int i);
// <---
int mx_count_of_fil(char **mass, t_argv *all);
int mx_isfileR(char *argv);
int mx_permcheck(char *argv, t_argv *all);

#endif
