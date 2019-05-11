/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** prints the given string
*/

int my_strlen(char const *str);

#include <unistd.h>

int my_putstr(char const *str)
{
    int len = my_strlen(str);

    write(1, str, len);
    return (len);
}
