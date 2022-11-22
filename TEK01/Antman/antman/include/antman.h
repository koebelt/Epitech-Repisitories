/*
** EPITECH PROJECT, 2021
** B-CPE-110-STG-1-1-antman-thomas.koebel
** File description:
** antman
*/

#ifndef ANTMAN_H_
#define ANTMAN_H_


/* INCLUDE */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int is_in_str(char c, char *str);
int my_strcmp(char const *s1, char const *s2);
char *open_that(int ac, char *filepath);
int fs_open_file(char const *filepath);
int getstat(char *filepath);
char **my_str_to_word_array(char const *str, char *separators);
int tab_length(char **tab);
int *fill_indexs(char **tab, int *index);
void my_put_nbr(int n);
int my_putstr(char const *str);
void my_putchar(char c);
int my_strlen(char const *str);

#endif /* !ANTMAN_H_ */
