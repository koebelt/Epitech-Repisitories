/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** save.c
*/

#include "include.h"

void init_save(window_obj_t *window_objects)
{
    char buffer[20];
    FILE * stream;

    stream = fopen("score.txt", "r");
    int count = fread(&buffer, sizeof(char), 20, stream);
    fclose(stream);
    window_objects->high_score = my_getnbr(buffer);
}

void write_on_save(window_obj_t *window_objects)
{
    FILE * stream;

    stream = fopen("score.txt", "w");
    fwrite(my_int_to_str(window_objects->high_score), 1,
    sizeof(my_int_to_str(window_objects->high_score)), stream);
    fclose(stream);
}
