/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday07-matheo.vitali
** File description:
** my_strncat
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int a = 0;

    while (dest[i] != '\0')
        i += 1;
    while (a < nb && src[a] != '\0') {
        dest[i] = src[a];
        a += 1;
        i += 1;
    }
    dest[i] = '\0';
    return (dest);
}