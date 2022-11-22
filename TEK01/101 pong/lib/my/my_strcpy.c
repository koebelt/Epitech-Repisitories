/*
** EPITECH PROJECT, 2020
** my_strcpy.c
** File description:
** 
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int a = 0;

    while (src[i] != '\0') {
        dest[a] = src[i];
        i += 1;
        a += 1;
    }
    if (src[i] == '\0') {
        dest[a] = src[i];
        return (dest);
    }
}
