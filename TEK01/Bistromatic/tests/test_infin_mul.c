/*
** EPITECH PROJECT, 2020
** bistro matic
** File description:
** test infin mul
*/

#include <criterion/criterion.h>
#include "../include/bistro.h"

Test(infin_mul, mul_pos_nbrs)
{
    char *str = infin_mul("12", "6");

    cr_assert_str_eq(str, "72");
    free(str);
}

Test(infin_mul, mul_neg_nbrs)
{
    char *str = infin_mul("-123", "-9");

    cr_assert_str_eq(str, "1107");
    free(str);
}

Test(infin_mul, mul_neg_nbr)
{
    char *str = infin_mul("-5651", "7");

    cr_assert_str_eq(str, "-39557");
    free(str);
}

Test(infin_mul, mul_neg_nbr_2)
{
    char *str = infin_mul("-9", "123546");

    cr_assert_str_eq(str, "-111204");
    free(str);
}

Test(infin_mul, mul_with_zeros_beginning)
{
    char *str = infin_mul("00084", "0963");

    cr_assert_str_eq(str, "80892");
    free(str);
}

Test(infin_mul, mul_by_zero)
{
    char *str = infin_mul("168841568546", "0");

    cr_assert_str_eq(str, "0");
    free(str);
}

Test(infin_mul, mul_by_zero_2)
{
    char *str = infin_mul("-465132456132", "0");

    cr_assert_str_eq(str, "0");
    free(str);
}

Test(infin_mul, mul_inf)
{
    char *str = infin_mul("741852963741852963741852963", "123456789987654321123456789");

    cr_assert_str_eq(str, "91586785546396877091586784722115806267305714722115807");
    free(str);
}

Test(infin_mul, mul_inf_neg)
{
    char *str = infin_mul("-362951847362951847362951847", "142753869142753869142753869");

    cr_assert_str_eq(str, "-51812780523571603995330427363463689891704866419946043");
    free(str);
}
