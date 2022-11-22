/*
** EPITECH PROJECT, 2021
** B-CPE-110-STG-1-1-antman-thomas.koebel
** File description:
** main
*/

int main(int ac, char **av)
{
    char *file = open_that(ac, av[1]);
    char *str = malloc(sizeof(char) * my_strlen(file));
    char *separators = " ',.";
    int i = 0;
    int y = 0;
    char *index = malloc(sizeof(char) * my_strlen(file));
    char **tab;

    if (error_handeling(ac, av))
        return (84);
    for (; file[i] != '|'; i++)
        str[i] = file[i];
    str[i] = '\0';
    tab = my_str_to_word_array(str, "@");
    i++;
    for (; file[i] != '\0'; i++, y++)
        index[y] = file[i];
    index[y] = '\0';
    display(index, tab, separators);
}

void display(char *index, char **tab, char *separators)
{
    int k = 0;
    char *n;

    for (int t = 0; index[t]; ++t) {
        for (; index[t] && is_in_str(index[t], separators); ++t)
            my_putchar(index[t]);
        n = malloc(sizeof(char) * 256);
        for (k = 0; index[t] && !is_in_str(index[t], separators); ++t, ++k)
            n[k] = index[t];
        n[k] = '\0';
        my_putstr(tab[my_getnbr(n) - 1]);
        t -= 1;
        free(n);
    }
}

int error_handeling(int ac, char **av)
{
    if (ac != 3)
        return (84);
    if (my_strcmp(av[2], "1") != 0)
        return (84);
}
