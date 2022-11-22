/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-thomas.koebel
** File description:
** my_printf.h
*/

#include <stdarg.h>
#include <unistd.h>

#ifndef MY_PRINTF_H
#define MY_PRINTF_H

void my_putchar(char, int *);
void my_putstr(char const *, int *);
void my_put_nbr(int, int *);
void my_put_unbr(unsigned int, int *);
int my_strlen(char *);
char *my_revstr(char *);
void my_hexa(unsigned long, int *);
void my_maj_hexa(unsigned int, int *);
void my_binary(unsigned int, int *);
int index_finder(char *, char);
int my_printf(char *, ...);
void printf_char(va_list *, int *);
void printf_str(va_list *, int *);
void printf_nstr(va_list *, int *);
void printf_nbr(va_list *, int *);
void printf_unbr(va_list *, int *);
void printf_hexa(va_list *, int *);
void printf_maj_hexa(va_list *, int *);
void printf_octal(va_list *, int *);
void printf_bin(va_list *, int *);
void printf_pointer(va_list *, int *);

#endif
