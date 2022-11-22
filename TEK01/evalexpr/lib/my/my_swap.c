/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** Exchange 2 variables values
*/

void my_swap(int *a, int *b)
{
    int c = *b;
    *b = *a;
    *a = c;
}
