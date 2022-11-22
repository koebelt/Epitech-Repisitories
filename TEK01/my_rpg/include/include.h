/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** include
*/

#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "struct.h"
#include "macro.h"
#include "../src/exterior/exterior.h"
#include "../src/menu/menu.h"
#include "../src/inventory/inventory.h"
#include "../src/items/items.h"
#include "../src/dongeon/dongeon.h"
#include "../src/pause/pause.h"

void init_sprite(sprite_t *new, sprite_info_t sprite_i, window_t *window);
void animate_sprite(sprite_t *sprite, window_t *window, int nb);
int	my_getnbr(const char *str);
int check_btn(window_t *window, sprite_t *button);
int change_texture(sprite_t *sprite, char *new_texture);
int load_bar(sprite_t *bar, float percent);
void init_item(window_t *window, item_info_t info, sprite_info_t sprite);
void create_items(window_t *window);
int mouse_click(sfSprite *sprite_button, sfVector2i mouse);
int mouse_hover(sfSprite *sprite_button, sfVector2i mouse);
int mouse_hover_item(sfSprite *sprite_button, sfVector2i mouse, item_t *item,
window_t *window);
int my_strcmp(char const *s1, char const *s2);
char *int_to_str(long long nb);
int my_strlen(char const *str);
void draw_indicators(window_t *window, quest_t *quest);
void update_quest(quest_t *quest, char *texte);
void draw_npcs(window_t *window);
void player_interact(window_t *window, quest_t *quest);
void init_quest(window_t *window, quest_t *quest, quest_info_t quest_i,
char *texte);
char *my_strcat(char *dest, char *src);
void accept_quest(quest_t *quest);
void return_quest(window_t *window, quest_t *quest);
void sound_set_audio(sfSound **sound, char *path, int volume);
void music_set_audio(sfMusic **music, char *path, int volume);
int randomize(void);
void init_sftext(text_t *text, int size, char *str, sfVector2f pos);
void animate_sprite_attack(sprite_t *sprite, window_t *window, int nb,
float delay);
void add_to_counter(monster_t *monster, npcs_with_quest_t *npcs);

#endif /* !INCLUDE_H_ */
