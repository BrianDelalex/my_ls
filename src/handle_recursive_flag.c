/*
** EPITECH PROJECT, 2019
** handle_recursive_flags.c
** File description:
** handles recursive flag
*/

#include "my_ls.h"
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

char **search_dir_to_open(char **dir_to_open, char *dirpath);

char **search_dir_to_open2(char **dir_to_open, struct dirent *read,
char *dirpath)
{
    if (my_strlen(dirpath) != 1 && dirpath[0] != '/')
        if (dirpath[0] == '.' && dirpath[1] == '/')
            dir_to_open = search_dir_to_open(dir_to_open, my_strconcat(dirpath,
        my_strconcat(read->d_name, "/")));
        else
            dir_to_open = search_dir_to_open(dir_to_open, my_strconcat(
        my_strconcat(dirpath, "/"), my_strconcat(read->d_name, "/")));
    else if (get_last_char_str(dirpath) != '/')
        dir_to_open = search_dir_to_open(dir_to_open, my_strconcat(dirpath,
    my_strconcat(read->d_name, "/")));
    return (dir_to_open);
}

char **search_dir_to_open(char **dir_to_open, char *dirpath)
{
    DIR *dir = opendir(dirpath);
    struct dirent *read;

    if (dir == NULL)  {
        my_puterror("File doesn't exist -R\n");
        exit(84);
    }
    dir_to_open = add_char_to_tab(dirpath, dir_to_open);
    for (read = readdir(dir); read != NULL; read = readdir(dir)) {
        if (read->d_type == DT_DIR && read->d_name[0] != '.')
            dir_to_open = search_dir_to_open2(dir_to_open, read, dirpath);
    }
    closedir(dir);
    return (dir_to_open);
}

void handle_recursive_flags(t_flags *flags)
{
    char **dir_to_open = malloc(sizeof(char *) * 1);

    dir_to_open[0] = NULL;
    for (int i = 0; i < flags->dir; i++) {
        dir_to_open = search_dir_to_open(dir_to_open, flags->dirpath[i]);
    }
    dir_to_open = sort_tab_in_alpha_order(dir_to_open);
    free(flags->dirpath);
    flags->dirpath = dir_to_open;
    for (int i = 0; flags->dirpath[i]; i++)
        flags->dir = i + 1;
}
