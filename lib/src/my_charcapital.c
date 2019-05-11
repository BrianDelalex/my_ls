/*
** EPITECH PROJECT, 2019
** my_charcapital.c
** File description:
** returns a capitalized value of the given char
*/

char my_charcapital(char c)
{
    if(c >= 97 && c <= 122)
        c = c - 32;
    return (c);
}
