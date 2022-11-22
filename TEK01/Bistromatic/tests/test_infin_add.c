/*
** EPITECH PROJECT, 2020
** bistro matic
** File description:
** test infin add
*/

#include <criterion/criterion.h>
#include "../include/bistro.h"

Test(infin_add, add_pos_nbr)
{
    char *str = infin_add("5", "10");

    cr_assert_str_eq(str, "15");
    free(str);
}

Test(infin_add, add_pos_nbr_2)
{
    char *str = infin_add("5150", "20");

    cr_assert_str_eq(str, "5170");
    free(str);
}

Test(infin_add, add_with_carries)
{
    char *str = infin_add("123456789", "876543211");

    cr_assert_str_eq(str, "1000000000");
    free(str);
}

Test(infin_add, add_zero)
{
    char *str = infin_add("0", "0");

    cr_assert_str_eq(str, "0");
    free(str);
}

Test(infin_add, add_with_zeros_beginning)
{
    char *str = infin_add("0050", "000151");

    cr_assert_str_eq(str, "201");
    free(str);
}

Test(infin_add, add_inf)
{
    char *str = infin_add("123123123123123123123123123123", "321321321321321321321321321");

    cr_assert_str_eq(str, "123444444444444444444444444444");
    free(str);
}

Test(infin_add, add_zero_to_nbr)
{
    char *str = infin_add("500", "0");

    cr_assert_str_eq(str, "500");
    free(str);
}

Test(infin_add, add_neg_nbr)
{
    char *str = infin_add("-5", "-10");

    cr_assert_str_eq(str, "-15");
    free(str);
}

Test(infin_add, add_neg_nbr_2)
{
    char *str = infin_add("-5150", "-20");

    cr_assert_str_eq(str, "-5170");
    free(str);
}

Test(infin_add, add_neg_with_carries)
{
    char *str = infin_add("-123456789", "-876543211");

    cr_assert_str_eq(str, "-1000000000");
    free(str);
}

Test(infin_add, add_neg_inf)
{
    char *str = infin_add("-123123123123123123123123123", "-321321321321321321321321321");

    cr_assert_str_eq(str, "-444444444444444444444444444");
    free(str);
}

Test(infin_add, add_zero_to_nbr_neg)
{
    char *str = infin_add("-500", "0");

    cr_assert_str_eq(str, "-500");
    free(str);
}
