/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** text_utilities
*/

#include "../../include/include.h"

void init_sftext(text_t *text, int size, char *str, sfVector2f pos)
{
    text->font = sfFont_createFromFile("assets/Fonts/Pixellari.ttf");
    text->text = sfText_create();
    text->pos.x = pos.x;
    text->pos.y = pos.y;
    sfText_setFont(text->text, text->font);
    sfText_setString(text->text, str);
    sfText_setCharacterSize(text->text, size);
    sfText_setColor(text->text, sfWhite);
    sfText_setPosition(text->text, text->pos);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}