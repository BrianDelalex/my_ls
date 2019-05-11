/*
** EPITECH PROJECT, 2019
** sort_tab_in_alpha_order.c
** File description:
** sorts a char tab in alpha order
*/

#include "my_ls.h"
#include <stdlib.h>

char my_charcapital(char c);

void find_lower_str2(char **tab, int i, char *lower, int *index)
{
    int status = 0;

    for (int j = 0; tab[i][j] && tab[*index][j]; j++)
        if (my_charcapital(tab[i][j]) < my_charcapital(tab[*index][j])) {
            *lower = tab[i][0];
            *index = i;
            status = 1;
            break;
        } else if (my_charcapital(tab[i][j]) > my_charcapital(tab[*index][j])) {
            status = 1;
            break;
        }
    if (status == 0) {
        if (my_strlen(tab[i]) < my_strlen(tab[*index])) {
            *lower = tab[i][0];
            *index = i;
        } else if (my_strlen(tab[i]) == my_strlen(tab[*index])) {
            *index = tab[i][0] > *lower ? i : *index;
            *lower = tab[i][0] > *lower ? tab[i][0] : *lower;
        }
    }
}

void find_lower_str(char **tab, int i, char *lower, int *index)
{
    if (my_charcapital(tab[i][0]) < my_charcapital(*lower)) {
        *lower = tab[i][0];
        *index = i;
    } else if (my_charcapital(tab[i][0]) == my_charcapital(*lower)) {
        find_lower_str2(tab, i, lower, index);
    }
}

char **sort_tab_in_alpha_order(char **tab)
{
    char **new_tab;
    int index = 0;
    char lower = 127;
    int len = 0;
    int k = 0;

    for (; tab[len]; len++);
    new_tab = malloc(sizeof(char *) * (len + 1));
    new_tab[len] = NULL;
    while (len >= 0) {
        for (int i = 0; tab[i]; i++)
            find_lower_str(tab, i, &lower, &index);
        new_tab[k] = tab[index];
        k++;
        len--;
        tab = remove_str_to_tab(tab, index);
        lower = 127;
        index = 0;
    }
    free(tab);
    return (new_tab);
}
