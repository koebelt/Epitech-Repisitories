/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** asm_next_next
*/

#include "../include/header.h"

void write_coding_byte(list_t *list, FILE *output)
{
    int nb_args = list->ptr.line.op.nbr_args;
    uint8_t byte = 0b00000000;
    int difference = 4 - nb_args;

    for (int i = 0; i < nb_args; ++i)
        write_coding_byte_next(list->ptr.line.op.type[i], &byte, i);
    while (difference > 0) {
        byte = byte << 2;
        --difference;
    }
    write(output->_fileno, &byte, 1);
}

int get_adress_of_line(list_t *list, list_t *mother)
{
    return (list->ptr.function.adress - mother->ptr.function.adress);
}

int goto_function(file_t *file, char *name, list_t *mother)
{
    for (list_t *tmp = file->lines; tmp; tmp = tmp->next) {
        if (tmp->id >= 100 && !my_strcmp(tmp->ptr.function.name, name))
            return (get_adress_of_line(tmp, mother));
    }
    return (0);
}

void write_cmdlist(file_t *file, FILE *output)
{
    for (list_t *tmp = file->lines; tmp; tmp = tmp->next) {
        if (tmp->id != 100 && my_strcmp(tmp->ptr.line.type, ".comment") &&
        my_strcmp(tmp->ptr.line.type, ".name"))
            write_cmd(tmp, output, file);
    }
}

void start_reading(char *path, FILE *output)
{
    char **file_in_tab = load_fcontent(path);
    file_t file = {(header_t){0}, NULL};

    for (int i = 0; file_in_tab[i] != NULL; i++) {
        if (file_in_tab[i][0] != '#' && file_in_tab[i][0] != '\n' &&
        file_in_tab[i][0] != '\r')
            put_in_cmdlist(file_in_tab[i], &file.lines);
    }
    add_byte(file.lines, &file.header);
    has_header(&file);
    read_header(file.lines, &file.header, output);
    write_cmdlist(&file, output);
}