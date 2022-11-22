/*
** EPITECH PROJECT, 2020
** bistro matic
** File description:
** header
*/

#ifndef _BISTRO_H_
#define _BISTRO_H_

char *infin_add(char *, char *);
char *sub_inf(char *, char *);
char *infin_mul(char *, char *);
char *infin_div(char *, char *);
char *infin_mod(char *, char *);
char *eval_expr(char *, char *);
char *calc(char *, char*);
char *insert_result(char *, char *, int, int);
char *small_strdup(char *, int, int);
char *str_format(char *, char *);
int errors(char *, char *, char *);
void par_pos(char *, int *, int *);
void add_pos(char *, int *, int *);
void prod_pos(char *, int *, int *);

#endif /* _BISTRO_H_ */
