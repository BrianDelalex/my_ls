/*
** EPITECH PROJECT, 2019
** find_length.c
** File description:
** find length of str to display in -l
*/

#include <my_ls.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <time.h>

void find_length2(t_length *lens, struct stat st)
{
    int len = 0;
    int len1 = 0;
    int len3 = 0;
    struct group *grp;

    grp = getgrgid(st.st_gid);
    for (;st.st_nlink > 0; st.st_nlink = st.st_nlink / 10)
        len = len + 1;
    if (len > lens->len_link)
        lens->len_link = len;
    for (; st.st_size > 0; st.st_size = st.st_size / 10)
        len1 = len1 + 1;
    if (len1 > lens->len_size)
        lens->len_size = len1;
    len3 = my_strlen(grp->gr_name);
    if (len3 > lens->len_grp)
        lens->len_grp = len3;
}

char *get_dirpath(char *dirpath)
{
    int i = 0;
    char *dirpath2;

    if (dirpath[0] == '.' && dirpath[1] == '/' && dirpath[2] == 0) {
        dirpath2 = malloc(sizeof(char) * 1);
        dirpath2[0] = 0;
        return (dirpath2);
    } else if ((dirpath[0] == '.' && dirpath[1] == 0) || dirpath[0] == 0) {
        dirpath2 = malloc(sizeof(char) * 1);
        dirpath2[0] = 0;
        return (dirpath2);
    } else {
        for (; dirpath[i]; i++);
        dirpath2 = malloc(sizeof(char) * (i + 2));
        for (int j = 0; dirpath[j]; j++)
            dirpath2[j] = dirpath[j];
        dirpath2[i] = '/';
        dirpath2[i + 1] = 0;
        return (dirpath2);
    }
}

void find_length(struct dirent *read, t_length *lens, char *dirpath)
{
    struct stat st;
    struct passwd *pwd;
    char *dirpath2;
    int len2 = 0;

    int st_rt = 0;

    dirpath2 = get_dirpath(dirpath);
    st_rt = stat(my_strconcat(dirpath2, read->d_name), &st);
    if (st_rt == -1) {
        my_puterror(my_strconcat(dirpath2, read->d_name));
        my_puterror("stat error\n");
        exit(84);
    }
    pwd = getpwuid(st.st_uid);
    len2 = my_strlen(pwd->pw_name);
    if (len2 > lens->len_user)
        lens->len_user = len2;
    find_length2(lens, st);
}
