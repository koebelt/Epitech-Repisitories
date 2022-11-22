/*
** EPITECH PROJECT, 2020
** bistro matic
** File description:
** test infin sub
*/

#include <criterion/criterion.h>
#include "../include/bistro.h"

Test(infin_sub, sub_nbr)
{
    char *str = infin_sub("15", "-5");

    cr_assert_str_eq(str, "10");
    free(str);
}

Test(infin_sub, sub_nbr_2)
{
    char *str = infin_sub("-15", "5");

    cr_assert_str_eq(str, "-10");
    free(str);
}

Test(infin_sub, sub_nbr_3)
{
    char *str = infin_sub("50", "-630");

    cr_assert_str_eq(str, "-580");
    free(str);
}

Test(infin_sub, sub_nbr_4)
{
    char *str = infin_sub("-50", "630");

    cr_assert_str_eq(str, "580");
    free(str);
}

Test(infin_sub, sub_nbr_equal_len)
{
    char *str = infin_sub("850", "-100");

    cr_assert_str_eq(str, "750");
    free(str);
}

Test(infin_sub, sub_nbr_equal_len_2)
{
    char *str = infin_sub("1295", "-9655");

    cr_assert_str_eq(str, "-8360");
    free(str);
}

Test(infin_sub, sub_nbr_res_is_zero)
{
    char *str = infin_sub("123456789", "-123456789");

    cr_assert_str_eq(str, "0");
    free(str);
}

Test(infin_sub, sub_with_carries)
{
    char *str = infin_sub("1000000001", "-2");

    cr_assert_str_eq(str, "999999999");
    free(str);
}

Test(infin_sub, sub_with_zeros_beginning)
{
    char *str = infin_sub("00000850", "-000125");

    cr_assert_str_eq(str, "725");
    free(str);
}

Test(infin_sub, sub_inf)
{
    char *str = infin_sub("987654329876543298765432223", "-111111111111111111111111224");

    cr_assert_str_eq(str, "876543218765432187654320999");
    free(str);
}
