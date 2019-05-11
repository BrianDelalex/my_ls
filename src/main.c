/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main function for my_ls project
*/

#include "my_ls.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    t_flags *flags = parsing(ac, av);

    flags->dirpath = sort_tab_in_alpha_order(flags->dirpath);
    if (flags->R == 1)
        handle_recursive_flags(flags);
    display_no_flags(flags);
    free(flags->dirpath);
    free(flags);
}
