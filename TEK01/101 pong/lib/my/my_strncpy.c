/*
** EPITECH PROJECT, 2020
** my_strncpy.c
** File description:
** 
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int g = 0;

    while (i < n) {
        dest[g] = src[i];
        i += 1;
        g += 1;
    }
    if (i > n)
        dest[g] = '\0';
    return (dest);
}