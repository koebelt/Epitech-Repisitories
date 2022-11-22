/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write
*/

#include "../include/header.h"

void write_register(file_t *file, FILE *output, char *arg, list_t *mother)
{
    long nb = 0;

    nb = my_getnbr(arg + 1);
    write(output->_fileno, &nb, 1);
}

void write_indirect(file_t *file, FILE *output, char *arg, list_t *mother)
{
    long number = 0;

    if (arg[0] == ':')
        number = goto_function(file, arg + 1, mother);
    else
        number = my_getnbr(arg);
    number = convert_big_endian_tiny(number);
    write(output->_fileno, &number, 2);
}

void write_direct(file_t *file, FILE *output, char *arg, list_t *mother)
{
    long nb = 0;

    if (arg[0] == '%' && arg[1] == ':')
        nb = goto_function(file, arg + 2, mother);
    else
        nb = my_getnbr(arg + 1);
    nb = convert_big_endian_small(nb);
    write(output->_fileno, &nb, 4);
}

void write_args(list_t *list, int i, FILE *output, file_t *file)
{
    void (*write_fcn[]) (file_t *, FILE *, char *, list_t *) = {write_register,
    write_direct, write_indirect};
    int tab[] = {T_REG, T_DIR, T_IND};

    if (is_index(list->ptr.line.op.mnemonique) && list->ptr.line.op.type[i]
    != T_REG) {
        list->ptr.line.op.args[i] += list->ptr.line.op.args[i][0] == '%' ?
        1 : 0;
        write_indirect(file, output, list->ptr.line.op.args[i], list);
        return;
    }
    for (int j = 0; j < 3; ++j) {
        if (tab[j] == list->ptr.line.op.type[i]) {
            write_fcn[j](file, output, list->ptr.line.op.args[i], list);
            break;
        }
    }
}

void write_cmd(list_t *list, FILE *output, file_t *file)
{
    int tab[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a,
    0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10};
    char *tab_command[] = {"live", "ld", "st", "add", "sub", "and", "or",
    "xor", "zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork", "aff", NULL};

    for (int i = 0; tab_command[i]; i++)
        if (!my_strcmp(tab_command[i], list->ptr.line.type)) {
            write(output->_fileno, &tab[i], 1);
            break;
        }
    if (has_coding_byte(list->ptr.line.type))
        write_coding_byte(list, output);
    for (int i = 0; i < 4; ++i) {
        if (!list->ptr.line.op.type[i])
            break;
        write_args(list, i, output, file);
    }
}