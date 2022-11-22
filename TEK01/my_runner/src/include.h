/*
** EPITECH PROJECT, 2020
** my_runner
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
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "struct.h"


#ifndef INCLUDE_H_
#define INCLUDE_H_

void my_putchar(char);
void my_putstr(char *);
void set_audio(sfSound **, char *);
void init_game(game_obj_t *, sfClock **, window_obj_t *window);
void game(window_obj_t *);
void init_dune(layer_t *);
void disp_layers(background_t *, sfRenderWindow **);
void init_game_layer(background_t *);
void init_dune(layer_t *);
void init_mount(layer_t *);
void init_ground_layer(layer_t *);
void init_grass(layer_t *);
void init_ground(sprite_t *);
void init_moon(sprite_t *);
void renit_cloud(layer_t *, int);
void renit_cloud2(layer_t *, int);
void init_jump(hero_t *, sfClock **);
void init_hero(sprite_t *, sfClock **);
void calc_layers(background_t *, sfRenderWindow **);
int anim_jump(hero_t *, window_obj_t *, obstacles_t *);
void anim_hero(hero_t *, sfClock **, sfRenderWindow **);
void init_grass2(layer_t *);
void init_cloud(layer_t *);
void init_cloud2(layer_t *);
char **my_str_to_word_array(char *);
void alloc_sprite_tab(char **, obstacles_t *);
void count_occurences(char **, obstacles_t *);
void disp_obs0(obstacles_t *, sfRenderWindow **, int);
void display_map(obstacles_t *, window_obj_t *, int);
void init_particles_sprites(hero_t *, int);
void init_death(hero_t *, sfClock *, sfSound *, window_obj_t *);
int death_particles(hero_t *, sfRenderWindow **, sfClock *);
void load_map(char *, window_obj_t *);
void load_obs0(obstacles_t *, int, int);
void init_obstacles(obstacles_t *);
int compute_collisions(hero_t *, obstacles_t *, window_obj_t *);
int anim_fall(hero_t *, window_obj_t *, obstacles_t *);
void init_fall(hero_t *, sfClock **);
void menu(window_obj_t *window);
void init_left(button_t *left);
char *my_strcat(char *dest, char *src);
char *my_int_to_str(int num);
void load_save(window_obj_t *window);
char **read_file(char const *path);
void win(window_obj_t *window);
void init_win(win_obj_t *win, window_obj_t *window);

#endif /* INCLUDE_H_ */
