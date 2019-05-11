/*
** EPITECH PROJECT, 2019
** parsing.c
** File description:
** parses the entries
*/

#include "my_ls.h"
#include <stdlib.h>

void check_flags2(char **av, t_flags *flags, int i, int j)
{
    switch(av[i][j]) {
    case 'R':
        flags->R = 1;
        break;
    case 'r':
        flags->r = 1;
        break;
    case 'd':
        flags->d = 1;
        break;
    case 'l':
        flags->l = 1;
        break;
    case 't':
        flags->t = 1;
        break;
    default :
        my_puterror("Unknown flag\n");
        exit(84);
    }
}
void check_flags(char **av, t_flags *flags, int i)
{
    for (int j = 1; av[i][j]; j++)
        check_flags2(av, flags, i, j);
}

void save_dirpath(t_flags *flags, char **av, int ac)
{
    if (flags->dir == 0) {
        flags->dir = 1;
        flags->dirpath = malloc(sizeof(char *) * 2);
        flags->dirpath[0] = malloc(sizeof(char) * 3);
        flags->dirpath[0][0] = '.';
        flags->dirpath[0][1] = '/';
        flags->dirpath[0][2] = 0;
        flags->dirpath[1] = NULL;
    } else {
        flags->dirpath = malloc(sizeof(char *) * (flags->dir + 1));
        for (int i = 0; i < flags->dir; i++)
            flags->dirpath[i] = av[ac - flags->dir + i];
        flags->dirpath[flags->dir] = NULL;
    }
}

t_flags *parsing(int ac, char **av)
{
    t_flags *flags = malloc(sizeof(t_flags));

    flags->dir = 0;
    flags->R = 0;
    flags->r = 0;
    flags->l = 0;
    flags->d = 0;
    flags->t = 0;
    for (int i = 1; av[i]; i++) {
        if (av[i][0] == '-')
            check_flags(av, flags, i);
        else
            flags->dir = flags->dir + 1;
    }
    save_dirpath(flags, av, ac);
    return (flags);
}
