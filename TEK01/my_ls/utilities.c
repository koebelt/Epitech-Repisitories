/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-thomas.koebel
** File description:
** utilities.c
*/

#include "include.h"

int file_exists(const char *path)
{
    struct stat buffer;
    int exist = stat(path, &buffer);
    if(exist == 0)
        return 1;
    else
        return 0;
}

int folder_exists(const char *path)
{
    struct stat s;
    int err = stat(path, &s);

    if(-1 == err)
        return (0);
    else {
        if(S_ISDIR(s.st_mode))
            return (1);
        else
            return (0);
    }
}

char *get_user(struct stat file)
{
    struct passwd *pws;
    pws = getpwuid(file.st_uid);
    return (pws->pw_name);
}

char *get_group(struct stat file)
{
    struct group *grp;
    grp = getgrgid(file.st_gid);
    return (grp->gr_name);
}
