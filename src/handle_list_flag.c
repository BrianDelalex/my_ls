/*
** EPITECH PROJECT, 2019
** handle_list_flag.c
** File description:
** handles the -l option
*/

#include "my_ls.h"
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

char *cut_ctime(char *ctime)
{
    char *str = malloc(sizeof(char) * 17);
    char *save = malloc(sizeof(char) * 4);
    int ct = 0;
    int i = 0;

    for (int i = 0; i < 3; i++)
        save[i] = ctime[i + 4];
    save[3] = 0;
    for (; ct == 0 || i < 11 ; i++) {
        ct = ctime[i + 4] == ':' ? ct + 1 : ct;
        if (i < 3)
            str[i] = ctime[i + 4];
        else
            str[i] = ctime[i + 5];
    }
    str[i] = 32;
    str[i + 1] = 0;
    free(save);
    return (str);
}

char **add_info_to_line(char **tab, int i, struct dirent *read, t_length *lens)
{
    struct stat st;
    struct passwd *pwd;
    struct group *grp;
    int st_rt = 0;

    lens->dirpath = get_dirpath(lens->dirpath);
    st_rt = stat(my_strconcat(lens->dirpath ,read->d_name), &st);
    if (st_rt == -1) {
        my_puterror("stat error 2");
        exit(84);
    }
    pwd = getpwuid(st.st_uid);
    grp = getgrgid(st.st_gid);
    tab[i] = my_strconcat(cut_ctime(ctime(&st.st_mtime)), tab[i]);
    tab[i] = my_strconcat(get_file_size(st.st_size, lens->len_size) ,tab[i]);
    tab[i] = my_strconcat(get_file_user(pwd->pw_name, lens->len_user), tab[i]);
    tab[i] = my_strconcat(get_file_user(grp->gr_name, lens->len_grp), tab[i]);
    tab[i] = my_strconcat(get_nb_of_link(st.st_nlink, lens->len_link), tab[i]);
    tab[i] = my_strconcat(get_mode(read, lens->dirpath), tab[i]);
    return (tab);
}

char **check_read_name(char **tab, int i, struct dirent *read, t_length *lens)
{
    if (my_strstr(tab[i], my_strconcat(read->d_name, "\n")) == 1)
        tab = add_info_to_line(tab, i, read, lens);
    return (tab);
}

char **handle_list_flag(char **tab, char *dirpath)
{
    DIR *dir = opendir(dirpath);
    struct dirent *read;
    t_length *len = malloc(sizeof(t_length));

    len->len_user = 0;
    len->len_size = 0;
    len->len_grp = 0;
    len->len_link = 0;
    len->dirpath = dirpath;
    for (read = readdir(dir); read != NULL; read = readdir(dir))
        if (read->d_name[0] != '.')
            find_length(read, len, dirpath);
    closedir(dir);
    dir = opendir(dirpath);
    for (read = readdir(dir); read != NULL; read = readdir(dir)) {
        for (int i = 0; tab[i]; i++)
            tab = check_read_name(tab, i, read, len);
    }
    closedir(dir);
    return (tab);
}
