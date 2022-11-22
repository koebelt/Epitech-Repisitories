/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** asm_next
*/

#include "../include/header.h"

void add_byte(list_t *list, header_t *header)
{
    int nb_bytes = 0;

    for (list_t *temp = list; temp; temp = temp->next) {
        if (temp->id != 100)
            temp->ptr.line.type[0] != '.' ? nb_bytes +=
            temp->ptr.line.nb_bytes : 0;
    }
    header->prog_size = nb_bytes;
}

char *get_str(char *str)
{
    char *new = NULL;
    int index = 0;
    int counter = 0;

    for (int i = 0; str[i]; i++)
        counter += (str[i] != '\"') ? 1 : 0;
    new = malloc(sizeof(char) * (counter + 1));
    for (int i = 0; str[i]; i++) {
        if (str[i] != '\"') {
            new[index] = str[i];
            index++;
        }
    }
    new[index] = '\0';
    if (new[my_strlen(new) - 1] == '\n' || new[my_strlen(new) - 1] == '\r')
        new[my_strlen(new) - 1] = '\0';
    return (new);
}

void write_header(header_t *header, FILE *output)
{
    uint32_t magic = convert_big_endian_small(header->magic);
    uint64_t size = convert_big_endian_tall(header->prog_size);

    write(output->_fileno, &magic, sizeof(uint32_t));
    write(output->_fileno, header->prog_name, PROG_NAME_LENGTH);
    write(output->_fileno, &size, sizeof(uint64_t));
    write(output->_fileno, header->comment, COMMENT_LENGTH);
}

void dump_header_memory(header_t *header)
{
    char *empty_name = malloc(sizeof(char) * (PROG_NAME_LENGTH));
    char *empty_comment = malloc(sizeof(char) * (COMMENT_LENGTH));

    for (int i = 0; i < PROG_NAME_LENGTH; ++i)
        empty_name[i] = '\0';
    for (int i = 0; i < COMMENT_LENGTH ; ++i)
        empty_comment[i] = '\0';
    my_memcpy(header->prog_name, empty_name, PROG_NAME_LENGTH);
    my_memcpy(header->comment, empty_comment, COMMENT_LENGTH);
}

void read_header(list_t *list, header_t *header, FILE *output)
{
    dump_header_memory(header);
    header->magic = COREWAR_EXEC_MAGIC;
    for (list_t *tmp = list; tmp != NULL; tmp = tmp->next) {
        for (int j = 0; j < 2; j++)
            read_header_next(tmp, j, header);
    }
    write_header(header, output);
}