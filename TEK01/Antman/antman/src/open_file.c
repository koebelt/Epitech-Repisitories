/*
** EPITECH PROJECT, 2021
** B-CPE-110-STG-1-1-antman-thomas.koebel
** File description:
** open_file
*/

#include "../include/antman.h"

char *open_that(int ac, char *filepath)
{
    int files = fs_open_file(filepath);
    int sizefile = getstat(filepath);
    char *buffer = malloc(sizeof(char) * sizefile);
    ac = ac * 2;
    if (files == -1)
        return (84);
    read(files, buffer, sizefile);
    close(files);
    return (buffer);
}


int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    return (fd);
}

int getstat(char *filepath)
{
    struct stat fileStat;

    if (stat(filepath, &fileStat) < 0)
        return 1;
    return (fileStat.st_size);
}
