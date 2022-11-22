/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-thomas.koebel
** File description:
** base_disp.c
*/

#include "include.h"

void disp_folder(char *path)
{
    DIR *dir;
    struct dirent *dent;

    dir = opendir(path);
    if(dir!=NULL) {
        while((dent=readdir(dir))!=NULL)
            if (dent->d_name[0] != '.')
                my_printf("%s  ", dent->d_name);
    } else if (file_exists(path) && !folder_exists(path))
        my_printf("%s  ", path[0] == '/' ? path : get_name(path));
    else {
        perror("my_ls");
    }
    my_printf("\n");
    closedir(dir);
}

void disp_folders(char *path, int i, char **av)
{
    DIR *dir;
    struct dirent *dent;

    dir = opendir(path);
    if(dir!=NULL && errno != 20) {
        if(i > 1)
            my_printf("\n\n");
        my_printf("%s:\n", path);
        while((dent=readdir(dir))!=NULL)
            if (dent->d_name[0] != '.')
                my_printf("%s  ",dent->d_name);
            if (file_exists(av[i + 1]) && !folder_exists(av[i + 1]))
                my_printf("\n\n");
    } else {
        perror("my_ls");
    }
    closedir(dir);
}

void base_disp_many(int ac, char **av)
{
    int disp_file = 0;
    int only_files = 1;

    for (int i = 1; i < ac; ++i) {
        if (file_exists(av[i]) && !folder_exists(av[i])) {
            my_printf("%s  ", av[i][0] == '/' ? av[i] : get_name(av[i]));
            av[i] = NULL;
            disp_file = 1;
        }
        if (folder_exists(av[i]))
            only_files = 0;
    }
    if (disp_file && !only_files)
        my_printf("\n\n");
    for (int i = 1; i < ac; ++i)
        if (av[i] != NULL)
            disp_folders(av[i], i, av);
    my_printf("\n");
}

int base_disp(int ac, char **av)
{
    if (ac == 1) {
        disp_folder(".");
        return (1);
    } if (ac == 2 && av[1][0] != '-') {
        disp_folder(av[1]);
        return (1);
    } else if (av[1][0] != '-') {
        base_disp_many(ac, av);
        return (1);
    }
    return (0);
}
