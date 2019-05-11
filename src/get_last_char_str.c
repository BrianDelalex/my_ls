/*
** EPITECH PROJECT, 2019
** get_last_char_str.c
** File description:
** returns the last char of the given str
*/

char get_last_char_str(char *str)
{
    int len = 0;

    for (; str[len]; len++);
    return (str[len - 1]);
}
