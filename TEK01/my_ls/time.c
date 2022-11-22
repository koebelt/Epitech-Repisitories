/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-thomas.koebel
** File description:
** time.c
*/

#include "include.h"

int tot_files(char *path)
{
    DIR *dir;
    struct dirent *dent;
    int total = 0;

    dir = opendir(path);
    if(dir!=NULL) {
        while((dent=readdir(dir))!=NULL) {
            if (dent->d_name[0] != '.')
                total += 1;
        }
    }
    closedir(dir);
    return (total);
}

void disp_time(char *path)
{
    DIR *dir;
    struct dirent *dent;
    struct stat *tab = malloc(sizeof(struct stat) * (tot_files(path) + 1));

    /*for (int i = 0; i < tot_files(path); ++i)
        tab[i] = malloc(sizeof(char) * 256);*/
    dir = opendir(path);
    int i = 0;
    if(dir!=NULL) {
        while((dent=readdir(dir))!=NULL)
            if (dent->d_name[0] != '.') {
                struct stat buffer;
                stat(my_strcat(path, dent->d_name), &buffer);
                tab[i] = buffer;
                ++i;
            }
    } else if (file_exists(path) && !folder_exists(path))
        my_printf("%s  ", path[0] == '/' ? path : get_name(path));
    else {
        perror("my_ls");
    }
    my_printf("\n");
    closedir(dir);
}
