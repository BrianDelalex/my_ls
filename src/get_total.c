/*
** EPITECH PROJECT, 2019
** get_total.c
** File description:
** get nb of files
*/

#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include "my_ls.h"

char *fill_str(char *str, int total, int alloc)
{
    str[0] = 't';
    str[1] = 'o';
    str[2] = 't';
    str[3] = 'a';
    str[4] = 'l';
    str[5] = 32;
    for (int i = alloc - 3; total > 0; total = total / 10, i--)
        str[i] = total % 10 + 48;
    str[alloc - 2] = '\n';
    str[alloc - 1] = 0;
    return (str);
}

char *get_total(char *dirpath)
{
    DIR *dir = opendir(dirpath);
    struct dirent *read;
    char *str;
    int len = 0;
    int alloc = 8;

    if (dir == NULL) {
        my_puterror("File doesn't exist 2\n");
        return (NULL);
    }
    for (read = readdir(dir); read != NULL; read = readdir(dir))
        if (read->d_name[0] != '.')
            len = len + 1;
    closedir(dir);
    for (int i = len; i > 0; i = i / 10)
        alloc = alloc + 1;
    str = malloc(sizeof(char) * alloc);
    str = fill_str(str, len, alloc);
    return (str);
}
