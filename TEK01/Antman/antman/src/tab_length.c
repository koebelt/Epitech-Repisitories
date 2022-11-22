/*
** EPITECH PROJECT, 2021
** B-CPE-110-STG-1-1-antman-thomas.koebel
** File description:
** tab_length
*/

int tab_length(char **tab)
{
    int i = 0;

    for (; tab[i]; ++i);
    return (i);
}
