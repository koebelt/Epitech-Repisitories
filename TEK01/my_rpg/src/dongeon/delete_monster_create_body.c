/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** delete_monster_create_body
*/

#include "dongeon.h"

void create_dead_body(monster_t *monster, window_t *window)
{
    switch (monster->type) {
        case 0:
            create_misc(&window->dongeon.player.current->miscs, window,
            (sprite_info_t){monster->sprite.pos.x, monster->sprite.pos.y,
            monster->sprite.scale.x, 0, 128, 48, 32,
            "assets/dongeon/skeleton_arc.png"}, 8);
            break;
        case 1:
            create_misc(&window->dongeon.player.current->miscs, window,
            (sprite_info_t){monster->sprite.pos.x, monster->sprite.pos.y,
            monster->sprite.scale.x, 0, 128, 48, 32,
            "assets/dongeon/skeleton_spear.png"}, 7);
            break;
        case 2:
            create_misc(&window->dongeon.player.current->miscs, window,
            (sprite_info_t){monster->sprite.pos.x, monster->sprite.pos.y,
            monster->sprite.scale.x, 0, 128, 48, 32,
            "assets/dongeon/skeleton_skull.png"}, 11);
            break;
    }
}

void delete_monster_2(monster_t **begin, monster_t *prev, monster_t *next,
monster_t *curent)
{
    if (prev == NULL)
        *begin = next;
    else
        prev->next = next;
    free(curent);
}

void delete_used_monster(monster_t **begin, window_t *window)
{
    monster_t *prev = NULL;
    monster_t *curent = *begin;
    monster_t *next;

    while (curent != NULL) {
        next = curent->next;
        if (curent->stats.health <= 0) {
            window->inventory.exp_int += 5 +  5 *
            pow(1.3, window->inventory.level_int - 1);
            add_to_counter(curent, &window->ext.npcs);
            create_dead_body(curent, window);
            delete_monster_2(begin, prev, next, curent);
            return;
        } else
            prev = curent;
        curent = next;
    }
}