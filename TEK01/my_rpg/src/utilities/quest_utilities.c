/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** quest_utilities
*/

#include "../../include/include.h"

void return_quest(window_t *window, quest_t *quest)
{
    if (quest->now == quest->obj && quest->done == 0) {
        quest->done = 1;
        get_rand_item(window);
        window->inventory.exp_int +=
        (30 + 5 * (window->inventory.level_int - 1));
    }
}

void accept_quest(quest_t *quest)
{
    if (quest->taken == 0) {
        quest->taken = 1;
        quest->show_quest = 1;
    }
}

void update_quest(quest_t *quest, char *texte)
{
    quest->str = texte;
    quest->str = my_strcat(quest->str, int_to_str(quest->now));
    quest->str = my_strcat(quest->str, " / ");
    quest->str = my_strcat(quest->str, int_to_str(quest->obj));
    if (quest->done == 0)
        sfText_setString(quest->text.text, quest->str);
    else
        sfText_setString(quest->text.text, "");
}

void draw_indicators(window_t *window, quest_t *quest)
{
    sfRenderWindow_drawSprite(window->window,
    quest->exclamation_mark.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, quest->question_mark.sprite,
    NULL);
    sfRenderWindow_drawSprite(window->window,
    quest->question_mark_complete.sprite, NULL);
}

void init_quest(window_t *window, quest_t *quest, quest_info_t quest_i,
char *texte)
{
    quest->text.font = sfFont_createFromFile(quest_i.path_text);
    quest->text.text = sfText_create();
    quest->text.pos.x = window->ext.npcs.scroll.pos.x + 140;
    quest->text.pos.y = window->ext.npcs.scroll.pos.y + 110 + quest_i.pos_y;
    quest->text.scale.x = quest_i.scale;
    quest->text.scale.y = quest_i.scale;
    quest->now = 0;
    quest->obj = quest_i.obj;
    quest->taken = 0;
    quest->done = 0;
    quest->show_quest = 0;
    update_quest(quest, texte);
    sfText_setFont(quest->text.text, quest->text.font);
    sfText_setString(quest->text.text, quest->str);
    sfText_setScale(quest->text.text, quest->text.scale);
    sfText_setOutlineColor(quest->text.text, sfBlack);
    sfText_setOutlineThickness(quest->text.text, 1.8);
}