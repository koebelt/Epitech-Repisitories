/*
** EPITECH PROJECT, 2020
** bistro matic
** File description:
** get positions
*/

void prod_pos(char *str, int *a, int *b)
{
    int i = 0;
    int j = 0;

    for ( ; str[i] != '*' && str[i] != '/' && str[i] != '%' && str[i] ; ++i);
    for (j = i - 1 ; str[j] >= '0' && str[j] <= '9' && j >= 0 ; --j);
    for (; (str[j] < '0' || str[j] > '9') && j >= 0 ; --j);
    *a = j == -1 ? 0 : j + 2;
    for (j = i + 1 ; (str[j] < '0' || str[j] > '9') && str[j] ; ++j);
    for (; str[j] >= '0' && str[j] <= '9' && str[j] ; ++j);
    *b = j - 1;
}

void add_pos(char *str, int *a, int *b)
{
    int i = 1;

    *a = 0;
    for (; str[i] != '+' && str[i] != '-'; i++);
    for (i = i + 2; str[i] >= '0' && str[i] <= '9'; i++);
    i--;
    *b = i;
}

void par_pos(char *str, int *a, int *b)
{
    int i = 0;
    int count = 0;

    for ( ; str[i] != '(' && str[i] ; ++i);
    *a = i;
    for ( ; str[i] ; ++i) {
        count += (str[i] == '(') ? 1 : 0;
        if (str[i] == ')' && count == 1) {
            *b = i;
            break;
        }
        count -= (str[i] == ')') ? 1 : 0;
    }
}
