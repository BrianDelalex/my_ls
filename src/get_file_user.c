/*
** EPITECH PROJECT, 2019
** get_user_file.c
** File description:
** return a the user of a file as a str
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *get_file_user(char *user, int len_user)
{
    char *str = malloc(sizeof(char) * (len_user + 2));
    int i = 0;

    for (; user[i]; i++)
        str[i] = user[i];
    for (; i < len_user + 1; i++)
        str[i] = 32;
    str[i] = 0;
    return (str);
}
