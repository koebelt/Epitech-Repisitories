/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday06-matheo.vitali
** File description:
** my_strncmp
*/

int my_strncmp(char  const *s1, char  const *s2, int n)
{
    int size_s1 = 0;
    int size_s2 = 0;

    for (int a = 0; a < n; a += 1) {
        size_s1 = size_s1 + s1[a];
        if (s1[a] == '\0')
            a == n;
    }
    for (int b = 0; b < n; b += 1) {
        size_s2 = size_s2 + s2[b];
        if (s2[b] == '\0')
            b = n;
    }
    if (size_s1 < size_s2)
        return (-1);
    if (size_s1 > size_s2)
        return (1);
    else
        return (0);
}