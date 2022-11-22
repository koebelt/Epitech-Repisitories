/*
** EPITECH PROJECT, 2020
** bistro matic
** File description:
** test positions
*/

#include <criterion/criterion.h>
#include "../include/bistro.h"

Test(positions, par_pos)
{
    int a = 0;
    int b = 0;
    char str[] = "3*(6+96)";

    par_pos(str, &a, &b);
    cr_assert_eq(a, 2);
    cr_assert_eq(b, 7);
}

Test(positions, par_pos_2)
{
    int a = 0;
    int b = 0;
    char str[] = "(6+96)*3+5*(69+9)";

    par_pos(str, &a, &b);
    cr_assert_eq(a, 0);
    cr_assert_eq(b, 5);
}

Test(positions, par_pos_3)
{
    int a = 0;
    int b = 0;
    char str[] = "3*(6+96*(5+9*(2-9)))";

    par_pos(str, &a, &b);
    cr_assert_eq(a, 2);
    cr_assert_eq(b, 19);
}

Test(positions, par_pos_4)
{
    int a = 0;
    int b = 0;
    char str[] = "3*(((((((((9)))))))))";

    par_pos(str, &a, &b);
    cr_assert_eq(a, 2);
    cr_assert_eq(b, 20);
}

Test(positions, add_pos)
{
    int a = 0;
    int b = 0;
    char str[] = "-6+9+87-9";

    add_pos(str, &a, &b);
    cr_assert_eq(a, 0);
    cr_assert_eq(b, 3);
}

Test(positions, add_pos_2)
{
    int a = 0;
    int b = 0;
    char str[] = "-6-95547587415545+87-9";

    add_pos(str, &a, &b);
    cr_assert_eq(a, 0);
    cr_assert_eq(b, 16);
}

Test(positions, add_pos_3)
{
    int a = 0;
    int b = 0;
    char str[] = "699-9+87-9";

    add_pos(str, &a, &b);
    cr_assert_eq(a, 0);
    cr_assert_eq(b, 4);
}

Test(positions, add_pos_4)
{
    int a = 0;
    int b = 0;
    char str[] = "-6+-9+87-9";

    add_pos(str, &a, &b);
    cr_assert_eq(a, 0);
    cr_assert_eq(b, 5);
}

Test(positions, prod_pos)
{
    int a = 0;
    int b = 0;
    char str[] = "56+985*74+9";

    prod_pos(str, &a, &b);
    cr_assert_eq(a, 3);
    cr_assert_eq(b, 8);
}

Test(positions, prod_pos_2)
{
    int a = 0;
    int b = 0;
    char str[] = "56+-985/-74+9";

    prod_pos(str, &a, &b);
    cr_assert_eq(a, 3);
    cr_assert_eq(b, 10);
}

Test(positions, prod_pos_3)
{
    int a = 0;
    int b = 0;
    char str[] = "-5456+85%-74+9";

    prod_pos(str, &a, &b);
    cr_assert_eq(a, 6);
    cr_assert_eq(b, 11);
}
