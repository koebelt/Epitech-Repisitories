/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-thomas.koebel
** File description:
** long.c
*/

#include "include.h"

void disp_type(struct stat file)
{
    (S_ISDIR(file.st_mode) != 0) ? my_printf("d") : 0;
    (S_ISBLK(file.st_mode) != 0) ? my_printf("b") : 0;
    (S_ISCHR(file.st_mode) != 0) ? my_printf("c") : 0;
    (S_ISLNK(file.st_mode) != 0) ? my_printf("l") : 0;
    (S_ISFIFO(file.st_mode) != 0) ? my_printf("p") : 0;
    (S_ISSOCK(file.st_mode) != 0) ? my_printf("s") : 0;
    (S_ISREG(file.st_mode) != 0) ? my_printf("-") : 0;
}

void disp_perms(struct stat file)
{
    disp_type(file);
    my_printf((file.st_mode & S_IRUSR) ? "r" : "-");
    my_printf((file.st_mode & S_IWUSR) ? "w" : "-");
    my_printf((file.st_mode & S_IXUSR) ? "x" : "-");
    my_printf((file.st_mode & S_IRGRP) ? "r" : "-");
    my_printf((file.st_mode & S_IWGRP) ? "w" : "-");
    my_printf((file.st_mode & S_IXGRP) ? "x" : "-");
    my_printf((file.st_mode & S_IROTH) ? "r" : "-");
    my_printf((file.st_mode & S_IWOTH) ? "w" : "-");
    my_printf((file.st_mode & S_IXOTH) ? "x" : "-");
    my_printf(" %d ", file.st_nlink);
}

void disp_date(char *date)
{
    date[16] = '\0';
    date += 4;
    my_printf("%s ", date);
}

void long_disp(char *path, int len)
{
    struct stat file;
    int exist = stat(path, &file);
    disp_perms(file);
    my_printf("%s ", get_user(file));
    my_printf("%s ", get_group(file));
    for (int i = 0; i < (len - my_nbr_len(file.st_size)); ++i)
        my_putchar(' ');
    my_printf("%d ", file.st_size);
    disp_date(ctime(&file.st_mtime));
    path[0] == '/' ? my_printf("%s\n", path) : my_printf("%s\n", get_name(path));
}

int calc_max_length(char *path)
{
    DIR *dir;
    struct dirent *dent;
    int len = 0;
    int total = 0;

    dir = opendir(path);
    if(dir!=NULL) {
        while((dent=readdir(dir))!=NULL) {
            if (dent->d_name[0] != '.') {
                struct stat file;
                stat(my_strcat(path[my_strlen(path)] != '/' ? my_strcat(path, "/") : path, dent->d_name), &file);
                len = my_nbr_len(file.st_size) > len ?
                my_nbr_len(file.st_size) : len;
                total += file.st_blocks;
            }
        }
        my_printf("total %d\n", total/2);
    }
    closedir(dir);
    return (len);
}

void disp_long_folder(char *path)
{
    DIR *dir;
    struct dirent *dent;
    int len = 0;

    dir = opendir(path);
    if(dir!=NULL) {
        len = calc_max_length(path);
        while((dent=readdir(dir))!=NULL)
            if (dent->d_name[0] != '.') {
                long_disp(my_strcat(path[my_strlen(path)] != '/' ? my_strcat(path, "/") : path, dent->d_name), len);
            }
    } else if (file_exists(path) && !folder_exists(path)) {
        long_disp(path, len);
    } else {
        perror("my_ls");
    }
    closedir(dir);
}

void disp_long_folders(char *path)
{
    DIR *dir;
    struct dirent *dent;
    int len = 0;

    dir = opendir(path);
    if(dir!=NULL) {
        my_printf("%s:\n", path);
        len = calc_max_length(path);
        while((dent=readdir(dir))!=NULL)
            if (dent->d_name[0] != '.') {
                long_disp(my_strcat(path[my_strlen(path)] != '/' ? my_strcat(path, "/") : path, dent->d_name), len);
            }
    } else if (file_exists(path) && !folder_exists(path)) {
        long_disp(path, len);
    } else {
        perror("my_ls");
    }
    closedir(dir);
}

void long_disp_many(int ac, char **av)
{
    int disp_file = 0;
    int only_files = 1;
    int folders = 0;

    for (int i = 2; i < ac; ++i) {
        if (file_exists(av[i]) && !folder_exists(av[i])) {
            disp_long_folder(av[i]);
            av[i] = NULL;
            disp_file = 1;
        }
        if (folder_exists(av[i]))
            only_files = 0;
    }
    if (disp_file && !only_files)
        my_printf("\n");
    for (int i = 2; i < ac; ++i)
        if (av[i] != NULL) {
            folders > 0 ? my_printf("\n") : 0;
            disp_long_folders(av[i]);
            ++folders;
        }
}
