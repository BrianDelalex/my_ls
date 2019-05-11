/*
** EPITECH PROJECT, 2019
** remove_char_from_str.c
** File description:
** remove char from char*
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *remove_char_from_str(char *str)
{
    char *new_str;
    int len = my_strlen(str);

    new_str = malloc(sizeof(char) * len);
    for (int i = 0; str[i]; i++)
        new_str[i] = str[i];
    new_str[len - 1] = 0;
    return (new_str);
}
