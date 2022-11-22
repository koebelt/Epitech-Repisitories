/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-bsbsq-thomas.koebel
** File description:
** my_tab_size.c
*/

int my_tab_size(char **tab)
{
    int size;
    for (size = 0; tab[size]; ++size);
    return (size);
}
