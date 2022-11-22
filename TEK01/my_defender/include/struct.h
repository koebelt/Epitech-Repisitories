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

typedef struct linked_list
{
    void *data;
    struct linked_list *next;
} linked_list_t;

typedef struct text {
    sfFont *font;
    sfText *text;
    sfVector2f pos;
} text_t;

typedef struct circle {
    sfCircleShape *circle;
    sfVector2f pos;
    float radius;
} circle_t;

typedef struct sprite_info {
    float pos_x;
    float pos_y;
    float scale_x;
    float scale_y;
    int rect_x;
    int rect_y;
    int rect_height;
    int rect_width;
    char *path_text;
} sprite_info_t;

typedef struct soldier_info {
    int health;
    int damages;
    int team;
    float cooldown;
    sprite_info_t walk_info;
    sprite_info_t attack_info;
    sprite_info_t health_bar_info;
} soldier_info_t;

typedef struct sprite {
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f scale;
    sfTexture *texture;
    sfVector2u size_text;
} sprite_t;

typedef struct soldiers {
    sprite_t sprite;
    sprite_t attack;
    sprite_t health_bar;
    int health;
    int max_health;
    int damages;
    int team;
    int id;
    float cooldown;
    float t_cooldown;
    float t_0;
    int is_attacking;
    struct soldiers *next;
} soldiers_t;

typedef struct projectile {
    sprite_t sprite;
    int target;
    int damages;
    int used;
    struct projectile *next;
} projectile_t;

typedef struct building {
    sprite_t sprite;
    circle_t range;
    float cooldown;
    float t_0;
    int damages;
    int id;
    int health;
    int max_health;
    sprite_t health_bar;
    projectile_t *projectiles;
    sprite_info_t projectile;
} building_t;

typedef struct building_info {
    int health;
    int cooldown;
    int damages;
    int radius;
    sprite_info_t info;
    int level;
    sprite_info_t health_bar_info;
    sprite_info_t projectile;
} building_info_t;

typedef struct card {
    sprite_t sprite;
    int cost;
    int is_moved;
    soldier_info_t info;
} card_t;

typedef struct ig_ui {
    sprite_t card_support;
    sprite_t play_level;
    sprite_t pause_level;
    card_t cards[6];
} ig_ui_t;

typedef struct menu {
    sprite_t background;
    sprite_t play;
    sprite_t exit;
    sprite_t banner;
    sprite_t music_on;
    sprite_t music_off;
    sprite_t music_bar;
    sprite_t sound_on;
    sprite_t sound_off;
    sprite_t sound_bar;
    sprite_t setting_button;
    sprite_t setting_menu;
    sprite_t setting_plus1;
    sprite_t setting_minus1;
    sprite_t setting_plus2;
    sprite_t setting_minus2;
    sprite_t setting_close;
    sprite_t how_to_play;
    sprite_t shop_button;
    sfMusic *music;
} menu_t;

typedef struct pause {
    sprite_t background;
    sprite_t menu;
    sprite_t continue_play;
    sprite_t return_to_menu;
} pause_t;

typedef struct level_info {
    int level;
    int cards;
    sprite_info_t icon;
    sprite_info_t background;
    building_info_t hdv;
    building_info_t tower_1;
    building_info_t tower_2;
    int gold;
} level_info_t;


typedef struct energy {
    sprite_t background;
    sprite_t energy_bar;
    text_t disp_value;
    float value;
    float t_0;
    float cooldown;
} energy_t;

typedef struct team {
    building_t hdv;
    building_t tower_1;
    building_t tower_2;
    soldiers_t *soldiers;
    energy_t energy;
} team_t;

typedef struct tower_placement {
    sprite_t background;
    sprite_t archer;
    sprite_t wizard;
    sprite_t inferno;
    sprite_t eagle;
    sprite_t tesla;
} tower_placement_t;

typedef struct shop_item {
    sprite_t icon;
    int levels;
    int *price;
} shop_item_t;

typedef struct shop {
    sprite_t background;
    sprite_t menu;
    sprite_t close_bt;
    shop_item_t archer_t_bt;
    shop_item_t eagle_t_bt;
    shop_item_t inferno_t_bt;
    shop_item_t tesla_t_bt;
    shop_item_t wizard_t_bt;
    shop_item_t hdv_bt;
    text_t gold;
} shop_t;

typedef struct howtpl {
    sprite_t background;
    sprite_t close_bt;
} howtpl_t;

typedef struct player {
    int gold;
    int hdv_lvl;
    int archer_lvl;
    int wizard_lvl;
    int inferno_lvl;
    int eagle_lvl;
    int tesla_lvl;
} player_t;

typedef struct level {
    int level;
    sprite_t icon;
    sprite_t background;
    int cards;
    team_t enemies;
    int gold;
} level_t;

typedef struct level_select {
    sprite_t background;
    sprite_t menu;
    sprite_t arrow_left;
    sprite_t arrow_right;
    sprite_t exit;
    level_t levels[12];
} level_select_t;

typedef struct ai {
    int choosed;
} ai_t;

typedef struct win_menu {
    sprite_t background;
    sprite_t window;
    sprite_t next;
    sprite_t menu_button;
    text_t score;
    text_t golds;
    sfSound *win_sound;
    int played;
} win_menu_t;

typedef struct loose_menu {
    sprite_t background;
    sprite_t window;
    sprite_t retry;
    sprite_t menu_button;
    sfSound *loose_sound;
    int played;
} loose_menu_t;

typedef struct game {
    sprite_t background;
    team_t allies;
    ai_t ai;
    ig_ui_t ig_ui;
    int has_started;
    tower_placement_t placement_top;
    tower_placement_t placement_bot;
    int top;
    int bot;
    sfMusic *music;
} game_t;

typedef struct window {
    sfEvent event;
    sfVideoMode mode;
    sfRenderWindow *window;
    sfClock *clock;
    sprite_t cursor;
    int index;
    menu_t menu;
    game_t game;
    pause_t pause;
    shop_t shop;
    howtpl_t how_to_play;
    win_menu_t win_menu;
    loose_menu_t loose_menu;
    level_select_t level_select;
    level_t level;
    player_t player;
    sfVector2i mouse;
    int music_volume;
    int sound_volume;
    sfSound *click;
} window_t;

#endif /* !STRUCT_H_ */
