/*
** EPITECH PROJECT, 2021
** B-CPE-110-STG-1-1-antman-thomas.koebel
** File description:
** my_strcmp
*/

int compare_similar(char const *s1, char const *s2)
{
    for (int i = 0; i < s1[i]; ++i) {
        if (s1[i] != s2[i])
            return (2);
    }
    return (0);
}

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
        return (compare_similar(s1, s2));
}
