/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday06-matheo.vitali
** File description:
** my_strcpm
*/

int my_strcmp(char const *s1, char const *s2)
{
    int a = 0;
    int b = 0;
    int size_s1 = 0;
    int size_s2 = 0;

    while (s1[a] != '\0') {
        size_s1 = size_s1 + s1[a];
        a += 1;
    }
    while (s2[b] != '\0') {
        size_s2 = size_s2 + s2[b];
        b += 1;
    }
    if (size_s1 < size_s2)
        return (-1);
    if (size_s1 > size_s2)
        return (1);
    else
        return (0);
}