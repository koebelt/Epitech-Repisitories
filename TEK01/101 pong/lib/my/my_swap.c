/*
** EPITECH PROJECT, 2020
** my_swap.c
** File description:
** a function that swaps the content of two integers
*/

void my_swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
