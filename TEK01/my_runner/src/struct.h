/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct sprite {
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f scale;
    sfTexture *texture;
    sfVector2u size_text;
    float t_0;
} sprite_t;

typedef struct text {
    sfFont *font;
    sfText *text;
    sfVector2f pos;
} text_t;

typedef struct particle {
    sprite_t sprite;
    int x0;
    int y0;
    int V0;
    float a;
    int to_disp;
} particle_t;

typedef struct hero {
    int time_0;
    sprite_t sprite;
    int v0;
    int y0;
    int is_jumping;
    int is_falling;
    int is_dead;
    particle_t death_particles[80];
} hero_t;

typedef struct layer {
    sprite_t sprite[6];
} layer_t;

typedef struct background {
    layer_t layers[7];
    sprite_t ground;
    sprite_t moon;
    sfColor background_color;
    int velocity;
} background_t;

typedef struct obstacles {
    char **tab;
    sprite_t obs0[20];
    sprite_t obs1[20];
    sprite_t obs2[20];
    sprite_t obs3[20];
    sprite_t obs4[20];
    sprite_t obs5[20];
    sprite_t obs6[20];
    sprite_t obs7[20];
    sprite_t obs8[20];
    sprite_t obs9[1];
    int nbr_of_occurences[10];
    int cell_size;
} obstacles_t;

typedef struct rectangle {
    sfRectangleShape *rect;
    sfVector2f pos;
    sfVector2f size;
} rectangle_t;

typedef struct game_obj {
    background_t background;
    obstacles_t obstacles;
    hero_t hero;
    float t_0;
    sfMusic *music;
    sfSound *jump;
    sfSound *death;
    char *map;
    rectangle_t bar;
    int percent;
    text_t percent_txt;
    int initial_space;
} game_obj_t;

typedef struct button {
    sprite_t sprite;
    sfFont *font;
    sfText *text;
    sfVector2f text_pos;
} button_t;

typedef struct menu_obj {
    sfMusic *music;
    button_t start;
    button_t reset;
    button_t quit;
    button_t left;
    button_t right;
    text_t map_txt;
    text_t map_percentage;
    int map_index;
} menu_obj_t;

typedef struct win_obj {
    text_t win_txt;
    button_t menu_button;
} win_obj_t;

typedef struct window_obj {
    game_obj_t game;
    menu_obj_t menu;
    win_obj_t win;
    sfEvent event;
    sfVideoMode mode;
    sfRenderWindow *window;
    sfClock *clock;
    int index;
    char **high_score;
} window_obj_t;

#endif /* STRUCT_H_ */
