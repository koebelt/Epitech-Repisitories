/*
** EPITECH PROJECT, 2021
** B-CPE-201-STG-2-1-corewar-thibaut.ruscher
** File description:
** my_strcmp
*/

static int compare_similar(char const *s1, char const *s2)
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

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    while (i != n - 1 && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i += 1;
    return (s1[i] - s2[i]);
}