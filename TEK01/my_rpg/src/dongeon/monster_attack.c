/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** monster_attack
*/

#include "dongeon.h"

void monster_attack_next(monster_t *monster, player_dong_t *player,
window_t *window, float prev_left)
{
    sfFloatRect box = sfSprite_getGlobalBounds(player->sprite.sprite);

    if (monster->sprite.rect.left == 19 *
    monster->sprite.rect.width && sfFloatRect_intersects(&box,
    &monster->attack_range, NULL) && prev_left !=
    monster->sprite.rect.left) {
        player->stats.health -= monster->stats.damage -
        window->inventory.armor_info;
    }
}

void monster_attack_first(monster_t *monster, window_t *window,
float prev_left)
{
    if (monster->sprite.rect.left == 8 * monster->sprite.rect.width
    && prev_left != monster->sprite.rect.left)
        create_arrow(&monster->spell, window, monster,
        monster->sprite.scale.x > 0 ? ARROW_SPEED : -ARROW_SPEED);
}

void monster_attack_second(monster_t *monster, player_dong_t *player,
window_t *window, float prev_left)
{
    sfFloatRect box = sfSprite_getGlobalBounds(player->sprite.sprite);

    if (monster->sprite.rect.left == 8 * monster->sprite.rect.width
    && sfFloatRect_intersects(&box, &monster->attack_range, NULL) &&
    prev_left != monster->sprite.rect.left)
        player->stats.health -= monster->stats.damage -
        window->inventory.armor_info;
}
void monster_attack(monster_t *monster, player_dong_t *player,
window_t *window, float prev_left)
{
    monster->attacking = 1;
    monster->sprite.rect.top = 64;
    if (monster->type == 0)
        monster_attack_first(monster, window, prev_left);
    else if (monster->type == 1)
        monster_attack_second(monster, player, window, prev_left);
    else
        monster_attack_next(monster, player, window, prev_left);
}