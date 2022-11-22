/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** prototypes for all fonction of the lib
*/

#ifndef MY_H
#define MY_H

void    my_swap(int *, int *);
char    *my_strupcase(char *);
char    *my_strstr(char *,char const *);
char    *my_strncpy(char *, char const *, int);
int     my_strncomp(char const *, char const *, int);
char    *my_strncat(char *, char const *, int);
char    *my_strlowcase(char *);
int     my_strlen(char const *);
int     my_str_isupper(char const *);
int     my_str_isprintable(char const *);
int     my_str_isnum(char const *);
int     my_str_islower(char const *);
int     my_str_isalpha(char const *);
char    *my_strcpy(char *, char const *);
int     my_strcmp(char const *, char const *);
int     my_strncmp(char const *, char const *, int);
char    *my_strcat(char *, char const *);
char    *my_strcapitalize(char *);
void    my_sort_int_array(int *, int);
int     my_showstr(char const *);
int     my_showmem(char const *, int);
char    *my_revstr(char *);
int     my_putstr(char const *);
int     my_put_nbr(int);
void    my_putchar(char);
int     my_is_prime(int);
int     my_isneg(int);
int     my_getnbr(char const *);
int     my_find_prime_sup(int);
int     my_compute_square_root(int);
int     my_compute_power_rec(int, int);
int     verify_previous_is_letter(char *, int);
int     verify_previous_character(char *, int );
char    verify_character(char *, int);
char    *my_str_is_bigger(char *, char *);
char    *my_strislower(char *, char *);
char    *my_strdup(char *);

int     operation(int, int, char);
int     verif_add(int, int, char);
int     verif_mult(int, int, char);
int     verif_modulo(int, int, char);

int     while_parse(char **, int, int);
int     my_parse_nbr(char **);
int     eval_expr_add(char **);
int     evan_expr_mult(char **);
int     eval_expr(char *);

#endif
