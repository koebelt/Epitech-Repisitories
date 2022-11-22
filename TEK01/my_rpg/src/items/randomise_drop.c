/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** randomise_drop
*/

#include "items.h"

char **create_new_tab(int number, ...)
{
    char **tab = malloc(sizeof(char *) * (number + 1));
    char *arg = NULL;
    va_list ap;

    tab[number] = NULL;
    va_start(ap, number);
    for (int i = 0; i < number; i++) {
        arg = va_arg(ap, char *);
        tab[i] = malloc(sizeof(char) * (my_strlen(arg) + 1));
        tab[i] = arg;
    }
    va_end(ap);
    return (tab);
}

void get_rand_item(window_t *window)
{
    item_info_t infos[] = {{1, 0, 0, 0, "book"}, {2, 0, 0, 0, "rune"},
    {1, 0, 0, 0, "ring"}, {0, 0, 0, 1, "arms"}, {0, 0, 0, 2, "arms"},
    {0, 0, 0, 2, "legs"}, {0, 0, 0, 4, "legs"}, {0, 0, 0, 4, "armor"},
    {0, 0, 0, 8, "armor"}, {0, 0, 0, 1, "feet"}, {0, 0, 0, 2, "feet"},
    {0, 0, 0, 2, "head"}, {0, 0, 0, 4, "head"}, {0, 0, 1, 0, "book"},
    {0, 0, 2, 0, "rune"}, {0, 0, 1, 0, "ring"}, {0, 0, 0, 1, "book"},
    {0, 0, 0, 2, "rune"}, {0, 0, 0, 1, "ring"}, {0, 1, 0, 0, "book"},
    {0, 2, 0, 0, "rune"}, {0, 1, 0, 0, "ring"}};
    char **tab = create_new_tab(22, DAMAGE_BOOK, DAMAGE_RUNE, DAMAGE_RING,
    ARMS1, ARMS2, LEGS1, LEGS2, ARMOR1, ARMOR2, FEET1, FEET2, HEAD1, HEAD2,
    SPEED_BOOK, SPEED_RUNE, SPEED_RING, ARMOR_BOOK, ARMOR_RUNE, ARMOR_RING,
    ATTACK_SPEED_BOOK, ATTACK_SPEED_RUNE, ATTACK_SPEED_RING);
    int rand = 0;

    rand = (random() % (22)) + 1;
    for (int i = 0; i < 23; i++)
        if (i == rand)
            init_item(window, infos[i - 1],
            (sprite_info_t){0, 0, 0.1, 0, 0, 0, 0, tab[i - 1]});
}