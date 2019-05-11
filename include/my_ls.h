/*
** EPITECH PROJECT, 2019
** my_ls.h
** File description:
** header for my_ls project
*/

#ifndef MY_LS_H_
#define MY_LS_H_

#include <dirent.h>

typedef struct s_flags
{
    int l;
    int R;
    int t;
    int r;
    int d;
    int dir;
    char **dirpath;
}t_flags;

typedef struct s_control
{
    char **str;
}t_control;

typedef struct s_length
{
    int len_size;
    int len_user;
    int len_grp;
    int len_link;
    char *dirpath;
}t_length;

int my_puterror(char const *str);
t_flags *parsing(int ac, char **av);
char **add_char_to_tab(char *str, char **str_tab);
void handle_recursive_flags(t_flags *flags);
char *my_strconcat(char *str1, char *str2);
void display_no_flags(t_flags *flags);
int my_putstr(char const *str);
char **remove_str_to_tab(char **tab, int index);
int my_strlen(char const *str);
char **sort_tab_in_alpha_order(char **tab);
char *remove_char_from_str(char *str);
char get_last_char_str(char *str);
char **handle_list_flag(char **tab, char *dirpath);
int my_strstr(char *str1, char *str2);
char *get_file_size(int st_size, int len_size);
char *get_file_user(char *user, int len_user);
void find_length(struct dirent *read, t_length *lens, char *dirpath);
char *get_nb_of_link(int link, int len_link);
char *get_mode(struct dirent *read, char *dirpath);
char *get_total(char *dirpath);
char *get_dirpath(char *dirpath);

#endif
