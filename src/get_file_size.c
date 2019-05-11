/*
** EPITECH PROJECT, 2019
** get_file_size.c
** File description:
** returns a str of the file size
*/

#include <stdlib.h>
#include <stdio.h>

char *get_file_size(int st_size, int len_size)
{
    char *str = malloc(sizeof(char) * (len_size + 6));
    int len = 0;
    int save = st_size;

    for (; st_size > 0; st_size = st_size / 10)
        len = len + 1;
    st_size = save;
    for (int i = len - 1; i >= 0; i--) {
        str[i] = save % 10 + 48;
        save = save / 10;
    }
    for (int i = len; i <= len_size; i++)
        str[i] = 32;
    str[len_size + 1] = 'O';
    str[len_size + 2] = 'c';
    str[len_size + 3] = 't';
    str[len_size + 4] = 32;
    str[len_size + 5] = 0;
    return (str);
}

char *get_nb_of_link(int link, int len_link)
{
    char *str = malloc(sizeof(char) * (len_link + 2));
    int len = 0;
    int save = link;

    for (; link > 0; link = link / 10)
        len = len + 1;
    link = save;
    for (int i = len - 1; i >= 0; i--) {
        str[i] = save % 10 + 48;
        save = save / 10;
    }
    for (int i = len; i <= len_link; i++)
        str[i] = 32;
    str[len_link + 1] = 0;
    return (str);
}
