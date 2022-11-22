/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-thomas.koebel
** File description:
** printf_nbr.c
*/

#include "my_printf.h"

void printf_nbr(va_list *arg_list, int *len)
{
    int n = va_arg(*arg_list, int);

    my_put_nbr(n, len);
}
void printf_unbr(va_list *arg_list, int *len)
{
    unsigned int n = va_arg(*arg_list, unsigned int);

    my_put_unbr(n, len);

}
