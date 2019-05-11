/*
** EPITECH PROJECT, 2018
** my_puterror.c
** File description:
** writes error message on error output
*/

#include <unistd.h>

int my_puterror(char const *str)
{
    int i = 0;

    while (str[i] != '\0' ) {
        write(2, &str[i], 1);
        i = i + 1;
    }
    return (0);
}
