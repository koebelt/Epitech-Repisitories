/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** move_spell
*/

#include "dongeon.h"

int move_projectile_mid(spell_t *spell, player_dong_t *player,
float proj_pos_x)
{
    sfFloatRect box = sfSprite_getGlobalBounds(spell->sprite.sprite);

    if (is_wall_collision_projectile((sfFloatRect) {proj_pos_x +
    spell->stats.speed, spell->sprite.pos.y, box.width, box.height},
    player->current->collisions, player->current->sprite.scale.x)) {
        spell->sprite.pos.x += spell->stats.speed;
        sfSprite_setPosition(spell->sprite.sprite, spell->sprite.pos);
    } else {
        delete_used_spell(&player->spell, spell->id);
        return (0);
    }
    return (1);
}

int move_projectile_end(spell_t *spell, player_dong_t *player,
window_t *window)
{
    if (!damage_enemies_at_range(spell, player->current->monsters, window));
    else {
        delete_used_spell(&player->spell, spell->id);
        return (0);
    }
    return (1);
}

int move_projectile(spell_t *spell, player_dong_t *player, window_t *window)
{
    sfFloatRect box = sfSprite_getGlobalBounds(spell->sprite.sprite);
    float proj_pos_x = spell->sprite.pos.x;

    if (spell->sprite.scale.x < 0)
        proj_pos_x -= box.width;
    if (move_projectile_mid(spell, player, proj_pos_x) == 0 ||
    move_projectile_end(spell, player, window) == 0)
        return (0);
    return (1);
}