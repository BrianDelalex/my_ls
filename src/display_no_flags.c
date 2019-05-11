/*
** EPITECH PROJECT, 2019
** display_no_flags.c
** File description:
** displays with no flag
*/

#include "my_ls.h"
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

char **read_dir(char **display, char *dirpath, t_flags *flags)
{
    DIR *dir = opendir(dirpath);
    struct dirent *read;
    char **sort = malloc(sizeof(char *) * 1);

    sort[0] = NULL;
    if (dir == NULL)  {
        my_puterror("File doesn't exist\n");
        exit(84);
    }
    for (read = readdir(dir); read != NULL; read = readdir(dir)) {
        if (read->d_name[0] != '.')
            sort = add_char_to_tab(my_strconcat(read->d_name, "\n"), sort);
    }
    sort = sort_tab_in_alpha_order(sort);
    if (flags->l == 1)
        handle_list_flag(sort, dirpath);
    for (int i = 0; sort[i]; i++)
        display = add_char_to_tab(sort[i], display);
    free(sort);
    closedir(dir);
    return (display);
}

void display_no_flags(t_flags *flags)
{
    char **display = malloc(sizeof(char *) * 1);

    display[0] = NULL;
    for (int i = 0; i < flags->dir; i++) {
        if (flags->l == 1)
            display = add_char_to_tab(get_total(flags->dirpath[i]), display);
        if (flags->dir > 1 && flags->dirpath[i][0] == '.' &&
    flags->dirpath[i][1] == '/' && my_strlen(flags->dirpath[i]) == 2)
            display = add_char_to_tab(my_strconcat(
        remove_char_from_str(flags->dirpath[i]), ":\n"), display);
        else if (flags->dir > 1)
            display = add_char_to_tab(my_strconcat(flags->dirpath[i], ":\n"),
        display);
        display = read_dir(display, flags->dirpath[i], flags);
        if (i + 1 != flags->dir)
            display = add_char_to_tab("\n", display);
    }
    for (int i = 0; display[i]; i++)
        my_putstr(display[i]);
    free(display);
}
