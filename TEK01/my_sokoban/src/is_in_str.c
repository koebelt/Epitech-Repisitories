/*
** EPITECH PROJECT, 2021
** B-CPE-110-STG-1-1-antman-thomas.koebel
** File description:
** is_in_str
*/

int is_in_str(char c, char *str)
{
    for (int i = 0; str[i]; ++i)
        if (str[i] == c)
            return (1);
    return (0);
}