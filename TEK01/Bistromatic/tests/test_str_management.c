/*
** EPITECH PROJECT, 2020
** bistro matic
** File description:
** test str management
*/

#include <criterion/criterion.h>
#include "../include/bistro.h"
#include "../include/my.h"

Test(str_management, small_strdup)
{
    char str[] = "568*9658*(968+987412)+65";
    char res = small_strdup(str, 10, 19);

    cr_assert_str_eq(res, "968+987412");
    free(res);
}

Test(str_management, small_strdup_2)
{
    char str[] = "-96+9874+8";
    char res = small_strdup(str, 0, 7);

    cr_assert_str_eq(res, "-96+9874");
    free(res);
}

Test(str_management, small_strdup_3)
{
    char str[] = "69+5*-9851+65";
    char res = small_strdup(str, 3, 9);

    cr_assert_str_eq(res, "5*-9851");
    free(res);
}

Test(str_management, insert_result)
{
    char str[] = my_strdup("568*9658*(968+987412)");
    char res = small_strdup(str, 10, 19);
    char *result = insert_result(str, res, 9, 20);

    cr_assert_str_eq(result, "568*9658*988380");
    free(result);
}

Test(str_management, insert_result_2)
{
    char str[] = my_strdup("-96+9874+8");
    char res = small_strdup(str, 0, 7);
    char *result = insert_result(str, res, 0, 7);

    cr_assert_str_eq(result, "9778+8");
    free(result);
}

Test(str_management, insert_result_3)
{
    char str[] = my_strdup("69+5*-9851+65");
    char res = small_strdup(str, 3, 9);
    char *result = insert_result(str, res, 3, 9);

    cr_assert_str_eq(result, "69+-49255+65");
    free(result);
}
