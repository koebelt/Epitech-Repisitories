/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday07-matheo.vitali
** File description:
** my_strcat
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int a = 0;

    while (dest[i] != '\0')
        i += 1;
    for (a = 0; src[a] != '\0'; a += 1, i += 1)
        dest[i] = src[a];
    if (src[a] == '\0')
        dest[i] = src[a];
    return (dest);
}