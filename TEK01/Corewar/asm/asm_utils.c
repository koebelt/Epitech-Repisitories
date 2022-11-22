/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** asm_utils
*/

#include "../include/header.h"

int has_coding_byte(char *type)
{
    char *indexs[] = {"live", "zjmp", "fork", "lfork", NULL};

    for (int i = 0; indexs[i]; i++)
        if (!my_strcmp(type, indexs[i]))
            return (0);
    return (1);
}

int is_index(char *type)
{
    char *indexs[] = {"zjmp", "ldi", "sti", "fork", "lldi", "lfork", NULL};

    for (int i = 0; indexs[i]; i++)
        if (!my_strcmp(type, indexs[i])) {
            return (1);
        }
    return (0);
}

int get_nb_args(args_type_t tab[4])
{
    int i = 0;

    for (i = 0; i < 4; i++)
        if (!tab[i])
            return (i);
    return (i);
}

void write_coding_byte_next(args_type_t type, uint8_t *byte, int i)
{
    int tab[] = {0b01, 0b11, 0b10};
    int types[] = {T_REG, T_IND, T_DIR};

    for (int j = 0; j < 3; ++j) {
        if (type == types[j]) {
            i != 0 ? *byte = *byte << 2 : 0;
            *byte |= tab[j];
        }
    }
}

char *add_cor_at_the_end(char *str)
{
    int i = 0;
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 3));

    for (i = 0; str[i] != '\0'; i++)
        new_str[i] = str[i];
    new_str[i - 1] = 'c';
    new_str[i] = 'o';
    new_str[i + 1] = 'r';
    new_str[i + 2] = '\0';
    return (new_str);
}