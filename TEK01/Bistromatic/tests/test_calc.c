/*
** EPITECH PROJECT, 2020
** bistro matic
** File description:
** tests calc
*/

#include <criterion/criterion.h>
#include "../include/bistro.h"
#include "../include/my.h"

Test(calc, get_number)
{
    char str[] = "-965*96";
    char *res = get_number(str);

    cr_assert_str_eq(res, "-965");
    free(res);
}

Test(calc, get_number_2)
{
    char str[] = "8764/-496";
    char *res = get_number(str);

    cr_assert_str_eq(res, "8764");
    free(res);
}

Test(calc, calc_add)
{
    char str[] = my_strdup("9658+744");
    char *res = calc(str);

    cr_assert_str_eq(res, "10402");
    free(res);
}

Test(calc, calc_sub)
{
    char str[] = my_strdup("-854-96");
    char *res = calc(str);

    cr_assert_str_eq(res, "-950");
    free(res);
}

Test(calc, calc_mul)
{
    char str[] = my_strdup("-965*96");
    char *res = calc(str);

    cr_assert_str_eq(res, "-92640");
    free(res);
}

Test(calc, calc_div)
{
    char str[] = my_strdup("96/7");
    char *res = calc(str);

    cr_assert_str_eq(res, "13");
    free(res);
}

Test(calc, calc_mod)
{
    char str[] = my_strdup("153215%10000");
    char *res = calc(str);

    cr_assert_str_eq(res, "3215");
    free(res);
}
