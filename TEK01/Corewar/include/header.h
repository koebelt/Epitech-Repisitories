/*
** EPITECH PROJECT, 2021
** boostrap_corewar
** File description:
** header
*/

#ifndef HEADER_H_
#define HEADER_H_

#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "op.h"

typedef unsigned long long uint64_t;
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;

typedef struct function {
    char *name;
    int adress;
} function_t;

typedef struct line {
    char *type;
    int nb_bytes;
    op_t op;
} line_t;

typedef struct type {
    line_t line;
    uint8_t number;
    function_t function;
} type_t;

typedef struct list {
    type_t ptr;
    int id;
    struct list *next;
} list_t;

typedef struct file {
    header_t header;
    list_t *lines;
} file_t;

void has_header(file_t *file);
int end_with_s(char *str);
void fill_empty_function(char **tab, list_t *element, list_t **list);
void check_line(line_t *line);
char **my_nstr_to_array(char *str, char *separator, int size);
char **my_str_to_word_array(char *str, char *separator);
int number_of_words(char *str, char *separator);
char *int_to_str(long long nb);
long my_getnbr(char const *str);
int my_strlen(char const *str);
char **load_fcontent(char *filename);
void *my_memcpy(void *dest, void *src, size_t);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strdup(char *str);
uint64_t convert_big_endian_tall(uint64_t number);
uint32_t convert_big_endian_small(uint32_t number);
uint16_t convert_big_endian_tiny(uint16_t number);
char *my_strcat(char *begin, char *end);
int my_tab_len(char **tab);
void add_byte(list_t *list, header_t *header);
char *get_str(char *str);
void write_header(header_t *header, FILE *output);
void dump_header_memory(header_t *header);
void read_header(list_t *, header_t *header, FILE *output);
void write_register(file_t *file, FILE *output, char *arg, list_t *mother);
void write_indirect(file_t *file, FILE *output, char *arg, list_t *mother);
void write_direct(file_t *file, FILE *output, char *arg, list_t *mother);
void write_args(list_t *list, int i, FILE *output, file_t *file);
void write_cmd(list_t *list, FILE *output, file_t *file);
void write_coding_byte(list_t *list, FILE *output);
int get_adress_of_line(list_t *list, list_t *mother);
int goto_function(file_t *file, char *name, list_t *mother);
void write_cmdlist(file_t *file, FILE *output);
void start_reading(char *path, FILE *output);
int has_coding_byte(char *type);
int is_index(char *type);
int get_nb_args(args_type_t tab[4]);
void write_coding_byte_next(args_type_t type, uint8_t *byte, int i);
void put_in_cmdlist(char *cmdline, list_t **list);
void read_header_next(list_t *tmp, int j, header_t *header);
char *add_cor_at_the_end(char *str);
void fill_line_next(list_t *element);
void put_in_cmdlist_next(list_t **list, list_t *element, list_t *tmp);
void put_in_cmdlist_second(char **tab, list_t *element, list_t **list,
list_t *tmp);
void calc_size_of_line(list_t *element);
void check_label_name(char *fct_name);

#endif /* !HEADER_H_ */