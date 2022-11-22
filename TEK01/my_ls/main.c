/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-thomas.koebel
** File description:
** main.c
*/

#include "include.h"

char *get_name(char *path)
{
    char *name;
    int path_len = my_strlen(path);
    int last_slash = 0;
    int i = 0;

    for (i = 0; path[i]; i++)
        if (path[i] == '/')
            last_slash = i + 1;
    if (i == 0)
        return (path);
        name = malloc(sizeof(char) * (path_len - last_slash));
    if (name == NULL)
        exit(0);
        for (i = last_slash; path[i]; i++)
        name[i - last_slash] = path[i];
    name[i - last_slash] = '\0';
    return (name);
}

int main_long_disp(int ac, char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'l' && av[1][2] == '\0' && ac == 2) {
        disp_long_folder("./");
        return (1);
    }
    if (av[1][0] == '-' && av[1][1] == 'l' && av[1][2] == '\0' && ac == 3) {
        disp_long_folder(av[2]);
        return (1);
    } else if (av[1][0] == '-' && av[1][1] == 'l' && av[1][2] == '\0') {
        long_disp_many(ac, av);
        return (1);
    }
    return (0);
}

int main_rec_disp(int ac, char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'R' && av[1][2] == '\0' && ac == 2) {
        disp_long_folder("./");
        return (1);
    }
    if (av[1][0] == '-' && av[1][1] == 'R' && av[1][2] == '\0' && ac == 3) {
        disp_long_folder(av[2]);
        return (1);
    } else if (av[1][0] == '-' && av[1][1] == 'R' && av[1][2] == '\0') {
        long_disp_many(ac, av);
        return (1);
    }
    return (0);
}

int main_time_disp(int ac, char **av)
{
    if (av[1][0] == '-' && av[1][1] == 't' && av[1][2] == '\0' && ac == 2) {
        disp_long_folder("./");
        return (1);
    }
    if (av[1][0] == '-' && av[1][1] == 't' && av[1][2] == '\0' && ac == 3) {
        disp_long_folder(av[2]);
        return (1);
    } else if (av[1][0] == '-' && av[1][1] == 't' && av[1][2] == '\0') {
        long_disp_many(ac, av);
        return (1);
    }
    return (0);
}


int main(int ac, char **av)
{
    char index_tab[6] = {'l', 'r', 'R', 'd', 't', 0};
    if (base_disp(ac, av))
        return (0);
    if (main_long_disp(ac, av))
        return (0);
}
