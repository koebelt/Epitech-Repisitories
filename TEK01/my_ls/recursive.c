/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-thomas.koebel
** File description:
** recursive.c
*/

void disp_rec(char **path)
{
    DIR *dir;
    struct dirent *dent;

    dir = opendir(path);
    if(dir!=NULL) {
        while((dent=readdir(dir))!=NULL) {
            if (dent->d_name[0] != '.') {
                struct stat file;

                stat(my_strcat(path, dent->d_name), &file);
            }
        }
    }
    closedir(dir);
}
