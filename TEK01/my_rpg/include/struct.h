/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** struct
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef STRUCT_H_
#define STRUCT_H_

/* ------------------------------ UTILITIES ------------------------------ */
typedef struct text {
    sfFont *font;
    sfText *text;
    sfVector2f pos;
    sfVector2f scale;
} text_t;

typedef struct circle {
    sfCircleShape *circle;
    sfVector2f pos;
    float radius;
} circle_t;

typedef struct sprite_info {
    float pos_x;
    float pos_y;
    float scale;
    int rect_left;
    int rect_top;
    int rect_width;
    int rect_height;
    char *path_text;
} sprite_info_t;

typedef struct sprite {
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f scale;
    sfTexture *texture;
    sfVector2u size_text;
    float t_0;
} sprite_t;

typedef struct item_info {
    int damage;
    int attack_speed;
    int speed;
    int armor;
    char *type;
} item_info_t;

typedef struct item {
    char *type;
    int id;
    int placed;
    int equiped;
    int x;
    int y;
    int equiped_x;
    int equiped_y;
    sprite_t item;
    item_info_t stats;
    struct item *next;
} item_t;
typedef struct quest_info {
    float pos_y;
    float scale;
    int obj;
    char *path_text;
} quest_info_t;

typedef struct quest {
    int done;
    int taken;
    int show_quest;
    int now;
    int obj;
    char *str;
    text_t text;
    sprite_t npj;
    sprite_t exclamation_mark;
    sprite_t question_mark;
    sprite_t question_mark_complete;
} quest_t;

typedef struct view {
    sfView *view;
    sfFloatRect size;
} view_t;

/* ------------------------------ UTILITIES ------------------------------- */

/* ------------------------------- DONGEONS ------------------------------- */

typedef struct loot_table {

} loot_table_t;
typedef struct enity_stats {
    float health;
    float damage;
    float speed;
} entity_stats_t;

typedef struct dongeon_misc {
    int type;
    sprite_t sprite;
    struct dongeon_misc *next;
} dongeon_misc_t;
typedef struct spell {
    int id;
    sprite_t sprite;
    entity_stats_t stats;
    struct spell *next;
} spell_t;

typedef struct monster {
    int type;
    sprite_t sprite;
    sfFloatRect attack_range;
    entity_stats_t stats;
    int walking;
    int attacking;
    loot_table_t loots;
    spell_t *spell;
    struct monster *next;
} monster_t;

typedef struct dongeon_door {
    struct dongeon_room *room;
    sfVector2i pos;
    sprite_t sprite;
} door_t;

typedef struct dongeon_room {
    int type;
    door_t doors[5];
    monster_t *monsters;
    dongeon_misc_t *miscs;
    sfVector2i pos;
    sprite_t sprite;
    sfImage *collisions;
    struct dongeon_room *next;
} dongeon_room_t;


typedef struct player_dong {
    sprite_t sprite;
    sfRectangleShape *rect;
    entity_stats_t stats;
    int walking;
    int attacking;
    float t_0;
    spell_t *spell;
    dongeon_room_t *current;
    text_t health;
    text_t health_nbr;
} player_dong_t;

typedef struct dongeon {
    dongeon_room_t *list;
    dongeon_room_t *entrance;
    player_dong_t player;
    sfMusic *easy_music;
    view_t view;
} dongeon_t;

/* ------------------------------- DONGEONS ------------------------------- */

/* ------------------------------- EXTERIOR ------------------------------- */

typedef struct dungeon_entrance {
    sprite_t sprite;
    char *name;
    text_t text;
} dungeon_entrance_t;

typedef struct player_ext {
    sprite_t sprite;
    sfRectangleShape *rect;
    sfFloatRect interact;
    int walking;
    float t_0;
} player_ext_t;

typedef struct npcs {
    sprite_t guard;
    sprite_t farmer;
} npcs_t;

typedef struct npcs_with_quest {
    int show_scroll;
    sprite_t scroll;
    quest_t first;
    quest_t second;
    quest_t third;
    quest_t fourth;
} npcs_with_quest_t;

typedef struct map {
    sfImage *image;
    sprite_t sprite;
    dungeon_entrance_t entrances[3];
} map_t;

typedef struct exterior {
    map_t map;
    player_ext_t player;
    npcs_t npc;
    npcs_with_quest_t npcs;
    view_t view;
    sfMusic *music;
} exterior_t;

/* ------------------------------- EXTERIOR ------------------------------- */

/* --------------------------------- MENU --------------------------------- */

typedef struct videosettings {
    sprite_t back;
    sprite_t music_title;
    sprite_t display_title;
    sprite_t bg;
    sprite_t sound_bar;
    sprite_t sound;
    sprite_t table;
    sprite_t plus_btn;
    sprite_t minus_btn;
    int framerate;
    int sound_status;
} videosettings_t;

typedef struct inventory {
    sfColor exp_color;
    int open;
    int removing;
    int damage_info;
    int attack_speed_info;
    int speed_info;
    int armor_info;
    int exp_int;
    int exp_cap_int;
    int level_int;
    int points_int;
    int damage_points;
    int attack_speed_points;
    int speed_points;
    int armor_points;
    sprite_t inventory;
    sprite_t bin;
    sprite_t bin_temp;
    sprite_t select;
    sprite_t board;
    text_t armor;
    text_t speed;
    text_t attack_speed;
    text_t damage;
    text_t armor_nbr;
    text_t speed_nbr;
    text_t attack_speed_nbr;
    text_t damage_nbr;
    text_t stat_damage;
    text_t stat_attack_speed;
    text_t stat_speed;
    text_t stat_armor;
    text_t stat_damage_nbr;
    text_t stat_attack_speed_nbr;
    text_t stat_speed_nbr;
    text_t stat_armor_nbr;
    text_t level;
    text_t level_nbr;
    text_t exp;
    text_t slash;
    text_t exp_nbr;
    text_t exp_next_lvl;
    text_t points;
    text_t points_nbr;
} inventory_t;

typedef struct settings {
    sprite_t back;
    sprite_t bg;
    sprite_t music_title;
    sprite_t display_title;
    sprite_t music;
    sprite_t table;
    sprite_t music_bar;
    sprite_t plus_btn;
    sprite_t minus_btn;
    videosettings_t videosettings;
    int music_status;
} settings_t;

typedef struct pause {
    sprite_t back;
    sprite_t bg;
    sprite_t table;
    sprite_t play;
    sprite_t settingsbtn;
    view_t view;
} pause_t;

typedef struct how_to_play {
    sprite_t how_to_play;
    sprite_t back;
} howtoplay_t;
typedef struct menu {
    sprite_t play;
    sprite_t settingsbtn;
    sprite_t bg;
    sprite_t htpbtn;
    settings_t settings;
    howtoplay_t htp;
    sfMusic *music;
} menu_t;

/* --------------------------------- MENU --------------------------------- */

/* -------------------------------- WINDOW -------------------------------- */

typedef struct window {
    sfEvent event;
    sfVideoMode mode;
    sfRenderWindow *window;
    sfColor color;
    sfClock *clock;
    sprite_t cursor;
    sfVector2i mouse;
    sfVector2f view_center;
    int music_volume;
    int sound_volume;
    int index;
    pause_t pause;
    item_t **equip_tab;
    item_t **inventory_tab;
    item_t *item;
    inventory_t inventory;
    menu_t menu;
    exterior_t ext;
    dongeon_t dongeon;
    int stackg;
    int stack;
} window_t;

/* -------------------------------- WINDOW -------------------------------- */

#endif /* !STRUCT_H_ */
