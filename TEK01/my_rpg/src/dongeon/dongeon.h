/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** dongeon
*/

#include "../../include/include.h"

#ifndef DONGEON_H_
#define DONGEON_H_

#define EASY_MUSIC "assets/musics/easy_music.ogg"

#define MAX_MONSTER 5
#define MIN_MONSTER 1

#define ARCHER_HEALTH 200
#define ARCHER_DAMAGE 50
#define ARCHER_SPEED 2

#define SKULL_HEALTH 250
#define SKULL_DAMAGE 100
#define SKULL_SPEED 2

#define SPEAR_HEALTH 350
#define SPEAR_DAMAGE 40
#define SPEAR_SPEED 2

#define PLAYER_HEALTH 350
#define PLAYER_DAMAGE 100
#define SPEED 2.8

#define SPELL_SPEED 2
#define ARROW_SPEED 3

#define MAP_1   map[0] = "6-3-1      \0";\
                map[1] = "    -      \0";\
                map[2] = "9-6-5-1    \0";\
                map[3] = "    - -    \0";\
                map[4] = "  0-2-3-4-1\0";\
                map[5] = NULL;

#define MAP_2   map[0] = "6-4-1-2-9  \0";\
                map[1] = "-   -      \0";\
                map[2] = "2-6-0-1-4-5\0";\
                map[3] = "    - -    \0";\
                map[4] = "  4-2-3    \0";\
                map[5] = NULL;

#define MAP_3   map[0] = "6-2-1      \0";\
                map[1] = "  - -      \0";\
                map[2] = "4-0-5-1    \0";\
                map[3] = "  -   -    \0";\
                map[4] = "  6-2-3-4-9\0";\
                map[5] = NULL;

#define MAP_4   map[0] = "0-2-1      \0";\
                map[1] = "- -        \0";\
                map[2] = "5-6-4-3    \0";\
                map[3] = "  -   -    \0";\
                map[4] = "9-6-2-3    \0";\
                map[5] = NULL;

#define MAP_5   map[0] = "6-2     6-0\0";\
                map[1] = "  -     -  \0";\
                map[2] = "  9-5-1-3  \0";\
                map[3] = "  -        \0";\
                map[4] = "  6-2      \0";\
                map[5] = NULL;



void load_dongeon(window_t *window, dongeon_t *dongeon, char **buffer);
void load_random_dongeon(window_t *window, dongeon_t *dongeon);
void init_dungeon(window_t *window);
void dungeon_events(window_t *window);
void run_dongeon(window_t *window);
void init_player_dong(player_dong_t *player, window_t *window);
void animate_player_dong(player_dong_t *player, window_t *window);
void player_dong_mvnt(player_dong_t *player, window_t *window);
void move_player_dong(player_dong_t *player, int x, int y);
int player_dong_door_collision(player_dong_t *player);
void summon_monsters(dongeon_room_t *room, window_t *window);
void display_monsters(window_t *window);
int is_wall_collision_monster(sfFloatRect rect, sfImage *img, float scale);
int is_wall_collision_projectile(sfFloatRect rect, sfImage *img, float scale);
void create_spell(spell_t **list, window_t *window, player_dong_t *player,
float speed);
void display_projectile(window_t *window);
void display_arrow(window_t *window, spell_t *spell, monster_t *monster);
void create_arrow(spell_t **list, window_t *window, monster_t *monster,
float speed);
void delete_used_spell(spell_t **begin, int id);
void create_misc(dongeon_misc_t **list, window_t *window, sprite_info_t info,
int type);
void display_miscs(window_t *window, dongeon_misc_t *list);
int move_arrow(spell_t *spell, monster_t *monster, player_dong_t *player,
window_t *window);
int damage_player_at_range(spell_t *spell, player_dong_t *player,
window_t *window);
void add_doors(dongeon_room_t *element, char **map, sfVector2i pos,
window_t *window);
void init_specific_room_type(dongeon_room_t *element, window_t *window);
void add_room(dongeon_room_t **list, char **map, sfVector2i pos,
window_t *window);
void animate_spear(monster_t *monster, window_t *window);
void animate_skull(monster_t *monster, window_t *window);
void animate_archer(monster_t *monster, window_t *window);
void summon_spear(monster_t *element, window_t *window);
void summon_skull(monster_t *element, window_t *window);
void summon_archer(monster_t *element, window_t *window);
void move_monster(player_dong_t *player, monster_t *monster);
void monster_attack(monster_t *monster, player_dong_t *player,
window_t *window, float prev_left);
void delete_used_monster(monster_t **begin, window_t *window);
void summon_monster(monster_t **list, window_t *window, dongeon_room_t *room);
void set_suitable_positions(monster_t *monster, dongeon_room_t *room);
void set_monster_orientation(monster_t *monster, sfVector2f tmp);
void link_doors(dongeon_room_t *list);
dongeon_room_t *check_specified_room(dongeon_room_t *list, sfVector2i pos);
int is_wall_collision_dong(sfImage *image, player_dong_t *player);
int move_projectile(spell_t *spell, player_dong_t *player, window_t *window);
int damage_enemies_at_range(spell_t *spell, monster_t *monster,
window_t *window);
void init_dungeon(window_t *window);
void run_dungeon_start(window_t *window, int i);
void run_dungeon_mid(window_t *window);
void animate_death(player_dong_t *player, window_t *window);


#endif /* !DONGEON_H_ */
