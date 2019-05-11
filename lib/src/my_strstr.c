/*
** EPITECH PROJECT, 2019
** my_strstr.c
** File description:
** checks if two str match
*/

int my_strlen(char const *str);

int my_strstr(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);

    if (len1 != len2)
        return (0);
    for (int i = 0; str1[i] && str2[i]; i++)
        if (str1[i] != str2[i])
            return (0);
    return (1);
}
