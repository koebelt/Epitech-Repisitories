/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** dungeons_entrances
*/

#include "exterior.h"

void init_entrances(map_t *map, window_t *window)
{
    init_sprite(&map->entrances[0].sprite, (sprite_info_t) {840, 300, 3, 0, 0,
    0, 0, "assets/dongeon/dungeon_entrance.png"}, window);
    map->entrances[0].name = "La Montagne";
    init_sftext(&map->entrances[0].text, 15, "Press 'E' to Enter",
    (sfVector2f){860, 320});
    init_sprite(&map->entrances[1].sprite, (sprite_info_t) {240, 540, 3, 0, 0,
    0, 0, "assets/dongeon/dungeon_entrance.png"}, window);
    map->entrances[1].name = "La Grotte";
    init_sftext(&map->entrances[1].text, 15, "Press 'E' to Enter",
    (sfVector2f){260, 560});
    init_sprite(&map->entrances[2].sprite, (sprite_info_t) {520, 980, 3, 0, 0,
    0, 0, "assets/dongeon/dungeon_entrance.png"}, window);
    map->entrances[2].name = "La Fissure";
    init_sftext(&map->entrances[2].text, 15, "Press 'E' to Enter",
    (sfVector2f){540, 1000});
}

void entrance_events(player_ext_t *player, map_t *map, window_t *window)
{
    sfFloatRect player_box = sfSprite_getGlobalBounds(player->sprite.sprite);
    sfFloatRect box;

    for (int i = 0; i < 3; ++i) {
        box = sfSprite_getGlobalBounds(map->entrances[i].sprite.sprite);
        if (sfKeyboard_isKeyPressed(sfKeyE) &&
        sfFloatRect_intersects(&box, &player_box, NULL)) {
            window->index = 3;
            init_dungeon(window);
        }
    }
}

void disp_entrances(map_t *map, window_t *window)
{
    sfFloatRect player_box = sfSprite_getGlobalBounds(
    window->ext.player.sprite.sprite);
    sfFloatRect box;

    for (int i = 0; i < 3; ++i) {
        box = sfSprite_getGlobalBounds(map->entrances[i].sprite.sprite);
        sfRenderWindow_drawSprite(window->window,
        map->entrances[i].sprite.sprite, NULL);
        if (sfFloatRect_intersects(&box, &player_box, NULL))
            sfRenderWindow_drawText(window->window,
            map->entrances[i].text.text, NULL);
    }
}