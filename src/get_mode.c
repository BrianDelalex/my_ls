/*
** EPITECH PROJECT, 2019
** get_mode.c
** File description:
** get modes of the file and return it as str
*/

#include <dirent.h>
#include <sys/stat.h>
#include "my_ls.h"
#include <stdlib.h>

char *get_mode2(char *str, struct stat st)
{
        str[1] = st.st_mode & S_IRUSR ? 'r' : '-';
        str[2] = st.st_mode & S_IWUSR ? 'w' : '-';
        str[3] = st.st_mode & S_IXUSR ? 'x' : '-';
        str[4] = st.st_mode & S_IRGRP ? 'r' : '-';
        str[5] = st.st_mode & S_IWGRP ? 'w' : '-';
        str[6] = st.st_mode & S_IXGRP ? 'x' : '-';
        str[7] = st.st_mode & S_IROTH ? 'r' : '-';
        str[8] = st.st_mode & S_IWOTH ? 'w' : '-';
        str[9] = st.st_mode & S_IXOTH ? 'x' : '-';
        str[10] = 32;
        str[11] = 0;
        if (st.st_mode & S_ISVTX && st.st_mode & S_IXOTH)
            str[9] = 't';
        else if (st.st_mode & S_ISVTX)
            str[9] = 'T';
        return (str);
}

char *get_type(struct stat st, char *str)
{
    if (S_ISREG(st.st_mode))
        str[0] = '-';
    if (S_ISDIR(st.st_mode))
        str[0] = 'd';
    if (S_ISLNK(st.st_mode))
        str[0] = 'l';
    if (S_ISSOCK(st.st_mode))
        str[0] = 's';
    if (S_ISBLK(st.st_mode))
        str[0] = 'b';
    if (S_ISCHR(st.st_mode))
        str[0] = 'c';
    if (S_ISFIFO(st.st_mode))
        str[0] = 'p';
    str = get_mode2(str, st);
    return (str);
}

char *get_mode(struct dirent *read, char *dirpath)
{
    struct stat st;
    char *str = malloc(sizeof(char) * 12);

    stat(my_strconcat(dirpath ,read->d_name), &st);
    str = get_type(st, str);
    return (str);
}
