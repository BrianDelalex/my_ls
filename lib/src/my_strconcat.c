/*
** EPITECH PROJECT, 2019
** my_strconcat.c
** File description:
** concat two str
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strconcat(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    char *new_str = malloc(sizeof(char) * (len1 + len2 + 1));
    int i = 0;

    for (; str1[i]; i++)
        new_str[i] = str1[i];
    for (int j = 0; str2[j]; j++, i++)
        new_str[i] = str2[j];
    new_str[i] = 0;
    return (new_str);
}
