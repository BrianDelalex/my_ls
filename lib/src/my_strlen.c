/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** returns the length of the given str
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i]; i++);
    return (i);
}
