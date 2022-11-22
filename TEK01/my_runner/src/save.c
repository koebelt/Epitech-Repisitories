/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myrunner-thomas.koebel
** File description:
** load_save.c
*/

#include "include.h"

void load_save(window_obj_t *window)
{
    char **save = read_file("save.txt");

    for (int i = 0; i < 3; ++i)
        window->high_score[i] = save[i];
}

void write_on_save(window_obj_t *window)
{
    FILE * stream;
    char *to_save = my_strcat(my_strcat(my_strcat(window->high_score[0], "\n"),
    my_strcat(window->high_score[1], "\n")),
    my_strcat(window->high_score[2], "\n"));

    stream = fopen("save.txt", "w");
    fwrite(to_save, 1, sizeof(to_save), stream);
    fclose(stream);
}
