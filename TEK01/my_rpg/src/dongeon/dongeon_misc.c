/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** dongeon_misc
*/

#include "dongeon.h"

void create_misc(dongeon_misc_t **list, window_t *window, sprite_info_t info,
int type)
{
    dongeon_misc_t *element;

    element = malloc(sizeof(*element));
    init_sprite(&element->sprite, info, window);
    if (info.scale < 0) {
        element->sprite.scale.y *= -1;
        sfSprite_setScale(element->sprite.sprite, element->sprite.scale);
    }
    element->type = type;
    element->next = *list;
    *list = element;
}

void animate_misc(dongeon_misc_t *misc, window_t *window)
{
    sfTime time = sfClock_getElapsedTime(window->clock);
    float seconds = time.microseconds / 1000000.0 - misc->sprite.t_0;

    if (seconds > 0.12) {
        if (misc->sprite.rect.left >= misc->sprite.rect.width *
        (misc->type - 1));
        else
            misc->sprite.rect.left += misc->sprite.rect.width;
        misc->sprite.t_0 = sfClock_getElapsedTime(window->clock).microseconds
        / 1000000.0;
    }
    sfSprite_setScale(misc->sprite.sprite, misc->sprite.scale);
    sfSprite_setTextureRect(misc->sprite.sprite, misc->sprite.rect);
    sfRenderWindow_drawSprite(window->window, misc->sprite.sprite, sfFalse);
}

void calc_valable_interactions(player_dong_t *player, dongeon_misc_t *misc,
window_t *window)
{
    sfFloatRect player_box = sfSprite_getGlobalBounds(player->sprite.sprite);
    sfFloatRect box = sfSprite_getGlobalBounds(misc->sprite.sprite);

    if (sfKeyboard_isKeyPressed(sfKeyEnter) && sfFloatRect_intersects(&box,
    &player_box, NULL)) {
        get_rand_item(window);
        if (window->ext.npcs.first.taken == 1)
            window->ext.npcs.first.now = 1;
        if (window->ext.npcs.fourth.taken == 1)
            window->ext.npcs.fourth.now = 1;
        window->index = 1;
    }
}

void display_miscs(window_t *window, dongeon_misc_t *list)
{
    dongeon_misc_t *tmp = list;

    while (tmp != NULL) {
        if (tmp->type > 1)
            animate_misc(tmp, window);
        else
            sfRenderWindow_drawSprite(window->window, tmp->sprite.sprite,
            NULL);
        if (tmp->type == 0)
            calc_valable_interactions(&window->dongeon.player, tmp, window);
        tmp = tmp->next;
    }
}