/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** prototypes for all fonction of the lib
*/

#include <stddef.h>

#ifndef MY_H
#define MY_H

typedef struct map {
    int height;
    int width;
    int max;
    int x;
    int y;
} t_map;

typedef struct square {
    int x;
    int y;
    int size;
} t_square;

int     my_strlen(char const *);
int     my_tab_size(char **);
void     my_putstr(char const *);
void    my_putchar(char);
char    **my_str_to_word_array(char const *);
int     str_to_array_loop(char const *, int, int, char **);
int     how_many_words(char const *);
char    **find(char **);
void    try_max(char **, t_map *, int, int);
int     check_fit(char **, t_map, t_square);

#endif
