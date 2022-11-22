/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** interact_utilities
*/

#include "../../include/include.h"

void add_to_counter(monster_t *monster, npcs_with_quest_t *npcs)
{
    if (monster->type != 2) {
        if (npcs->second.taken == 1 && npcs->second.now != npcs->second.obj) {
            npcs->second.now += 1;
            update_quest(&npcs->second, "Tuer des squelettes ! ");
        }
    }
    if (npcs->third.taken == 1 && npcs->third.now != npcs->third.obj) {
        npcs->third.now += 1;
        update_quest(&npcs->third, "Eliminer quelques monstres ! ");
    }
}

void show_quest_log(window_t *window)
{
    if (window->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyJ)) {
        if (window->ext.npcs.show_scroll == 0)
            window->ext.npcs.show_scroll = 1;
        else
            window->ext.npcs.show_scroll = 0;
    }
}

void draw_npcs(window_t *window)
{
    sfRenderWindow_drawSprite(window->window, window->ext.npc.guard.sprite,
    NULL);
    sfRenderWindow_drawSprite(window->window, window->ext.npc.farmer.sprite,
    NULL);
    sfRenderWindow_drawSprite(window->window,
    window->ext.npcs.first.npj.sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->ext.npcs.second.npj.sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->ext.npcs.third.npj.sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->ext.npcs.fourth.npj.sprite, NULL);
}

void player_interact(window_t *window, quest_t *quest)
{
    sfFloatRect player =
    sfSprite_getGlobalBounds(window->ext.player.sprite.sprite);
    sfFloatRect interact = sfSprite_getGlobalBounds(quest->npj.sprite);

    if (sfFloatRect_intersects(&interact, &player, NULL) &&
    (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue)) {
        accept_quest(quest);
        return_quest(window, quest);
    }
}