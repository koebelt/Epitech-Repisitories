/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; ++i);
    return (i);
}
