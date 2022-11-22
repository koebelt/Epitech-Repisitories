/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** include.h
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

#ifndef INCLUDE_H_
#define INCLUDE_H_

typedef struct particle {
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f scale;
    sfTexture *texture;
    sfVector2u size_text;
    int rot_rate;
    int x0;
    int y0;
    int V0;
    float a;
    int to_disp;
} particle_t;

typedef struct particles {
    particle_t particle_tab[20];
} particles_t;

typedef struct bottle {
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f scale;
    sfTexture *texture;
    sfVector2u size_text;
    int x0;
    int y0;
    int V0;
    float a;
    int is_left;
    int rot_rate;
    int breaked;
} bottle_t;

typedef struct sprite {
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f scale;
    sfTexture *texture;
    sfVector2u size_text;
    int shooting;
} sprite_t;

typedef struct button {
    sprite_t sprite;
    sfFont *font;
    sfText *text;
    sfVector2f text_pos;
} button_t;

typedef struct game_obj {
    sprite_t hunter;
    sprite_t hand;
    sprite_t crosshair;
    bottle_t bottle;
    particles_t particles;
    particle_t bullet;
    sfSound *breaking_bottle;
    sfSound *gun;
    sfClock *anim_clock;
    sfClock *mvmnt_clock;
    sfClock *particle_clock;
    sfClock *hand_clock;
    sfClock *bullet_clock;
    sfFont *font;
    sfText *text;
    sfVector2f text_pos;
    int score;
    int health;
    sprite_t health_bar;
    sfMusic *music;
} game_obj_t;

typedef struct menu_obj {
    button_t start;
    button_t choose;
    button_t restart;
    sprite_t hunter;
    sprite_t hand;
    sprite_t crosshair;
    sfClock *anim_clock;
    sfClock *hand_clock;
    sfFont *font;
    sfText *text;
    sfVector2f text_pos;
    sfMusic *music;
} menu_obj_t;

typedef struct choose_bottles {
    button_t bottle0;
    button_t bottle1;
    button_t bottle2;
    button_t bottle3;
    button_t bottle4;
    button_t bottle5;
} choose_bottles_t;

typedef struct choose_obj {
    choose_bottles_t bottles;
    sprite_t hunter;
    sprite_t hand;
    sprite_t crosshair;
    sfClock *anim_clock;
    sfClock *hand_clock;
    sfFont *font;
    sfText *text;
    sfVector2f text_pos;
    int bottle_index;
} choose_obj_t;

typedef struct window_obj {
    game_obj_t game;
    menu_obj_t menu;
    choose_obj_t choose;
    sfEvent event;
    sfVideoMode mode;
    sfRenderWindow *window;
    sfColor background;
    int index;
    int high_score;
    int score;
} window_obj_t;

int	my_getnbr(const char *);
void my_putchar(char);
void my_putstr(char *);
void move_rect(sfIntRect *, int);
void break_bottle(bottle_t *, sfRenderWindow **);
void init_bottle(bottle_t *bottle);
void calc_one_bottle(bottle_t *, sfRenderWindow **, sfClock *);
void init_hunter(sprite_t *);
void anim_hunter(sprite_t *, sfClock **, sfVector2i, sfRenderWindow **);
void init_hand(sprite_t *);
void calc_hand(sprite_t *, sfVector2i, sfRenderWindow **, sfClock **);
void init_crosshair(sprite_t *);
void move_crosshair(sprite_t *, sfVector2i, sfRenderWindow **);
void init_particles(particles_t *, bottle_t *);
void explose_particles(particles_t *, sfRenderWindow **, sfClock *);
void init_bullet(particle_t *);
void calc_bullet(particle_t *, sfRenderWindow **, sfClock *);
void set_audio(sfSound **, char *);
void init_game(game_obj_t *);
int game_mouse_click(sfMouseButtonEvent, bottle_t *, sfRenderWindow **);
int analyse_game_events(window_obj_t *);
void game_events(window_obj_t *);
void game_play(window_obj_t *);
void disp_game(window_obj_t *, sfVector2i);
void init_menu(menu_obj_t *);
void menu_play(window_obj_t *);
void menu_events(window_obj_t *);
void anim_start(button_t *, sfVector2i, sfRenderWindow **);
void init_start(button_t *);
void init_choose(button_t *);
void anim_choose(button_t *, sfVector2i, sfRenderWindow **);
void init_reset(button_t *);
void anim_reset(button_t *, sfVector2i, sfRenderWindow **);
char *my_strcat(char *, char *);
char *my_int_to_str(int);
void init_choose_menu(choose_obj_t *);
void disp_high_score(window_obj_t *);
void choose_play(window_obj_t *);
void init_wwhine(button_t *);
void init_rwhine(button_t *);
void init_wiskey(button_t *);
void init_bwhine(button_t *);
void init_gwhine(button_t *);
void init_champagne(button_t *);
void disp_wwhine(button_t *, sfVector2i, sfRenderWindow **);
void disp_rwhine(button_t *, sfVector2i, sfRenderWindow **);
void disp_wiskey(button_t *, sfVector2i, sfRenderWindow **);
void disp_bwhine(button_t *, sfVector2i, sfRenderWindow **);
void disp_gwhine(button_t *, sfVector2i, sfRenderWindow **);
void disp_champagne(button_t *, sfVector2i, sfRenderWindow **);
void init_health(sprite_t *);
void disp_health(game_obj_t *, sfRenderWindow **);
void init_save(window_obj_t *);
void write_on_save(window_obj_t *);
void init_choose_menu(choose_obj_t *);
int choose_mouse_click(sfMouseButtonEvent, choose_obj_t *);
int analyse_choose_events(window_obj_t *);
void change_index(window_obj_t *, int);

#endif /* INCLUDE_H_ */
