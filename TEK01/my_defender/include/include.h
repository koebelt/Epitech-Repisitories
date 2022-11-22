/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** include
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
#include "macro.h"

#ifndef INCLUDE_H_
#define INCLUDE_H_

void init_building(building_t *building, building_info_t info,
sfClock **clock);
int tower_attack(building_t *building, soldiers_t *enemy, sfClock **clock);
int has_an_enemy_in_range(building_t *build, soldiers_t *enemy,
sfClock **clock);
void anim_building_health_bar(building_t *building, window_t *window);
void display_building(building_t *build, window_t *window, soldiers_t *enemies);
int intersects(circle_t circle, sfFloatRect rect);
void display_buildings(game_t *game, window_t *window);
void init_placement(tower_placement_t *placement, sfVector2f pos, player_t *pl);
void init_choosing(game_t *game, window_t *window);
void placement_event(tower_placement_t *pa, sfMouseButtonEvent m, window_t *w,
int p);
void disp_placement(tower_placement_t *placement, window_t *window);
void disp_choosing(game_t *game, window_t *window);
void tesla_placement(tower_placement_t *pa, sfMouseButtonEvent m, window_t *w,
int p);
void eagle_placement(tower_placement_t *pa, sfMouseButtonEvent m, window_t *w,
int p);
void inferno_placement(tower_placement_t *pa, sfMouseButtonEvent m, window_t *w,
int p);
void wizard_placement(tower_placement_t *pa, sfMouseButtonEvent m, window_t *w,
int p);
void archer_placement(tower_placement_t *pa, sfMouseButtonEvent m, window_t *w,
int p);
void init_ai(window_t *window);
int ai_place_monster(window_t *window);
void init_energy(energy_t *energy, sfClock **clock);
void display_energy(energy_t *energy, window_t *window);
int game_released_event(game_t *game, sfMouseButtonEvent mouse,
window_t *window);
int analyse_game_events(window_t *window);
void game2(window_t *window);
void game(window_t *window);
int init_game(game_t *game, sfClock **clock, window_t *window);
void init_game2(game_t *game, sfClock **clock, window_t *window);
void card_picked(game_t *game, sfMouseButtonEvent mouse, card_t *card);
void card_released(game_t *game, sfMouseButtonEvent mouse,
window_t *window, card_t *card);
int game_mouse_event(game_t *game, sfMouseButtonEvent mouse, window_t *window);
void init_how_to_play(howtpl_t *how_to_play, window_t *window);
int howtpl_mouse_event(howtpl_t *how_to_play, sfMouseButtonEvent mouse,
window_t *window);
int analyse_level_howtpl(window_t *window);
void how_to_play(window_t *window);
void display_card(card_t *card, window_t *window);
void display_ig_ui(ig_ui_t *ig_ui, window_t *window);
void init_card(card_t *card, sprite_info_t info, int cost,
soldier_info_t soldier_info);
void init_ig_ui(ig_ui_t *ig_ui);
void init_ig_ui2(ig_ui_t *ig_ui);
void init_ig_ui3(ig_ui_t *ig_ui);
void level_mouse_event(level_select_t *levels, sfMouseButtonEvent mouse,
window_t *window);
int analyse_level_events(window_t *window);
void level_select(window_t *window);
void level_select2(window_t *window);
void level_select3(window_t *window);
void init_level(level_t *level, level_info_t info, sfClock **clock);
void init_levels(level_select_t *levels, sfClock **clock);
void init_levels2(level_select_t *levels, sfClock **clock);
void init_levels3(level_select_t *levels, sfClock **clock);
void init_levels4(level_select_t *levels, sfClock **clock);
void init_levels5(level_select_t *levels, sfClock **clock);
void init_levels6(level_select_t *levels, sfClock **clock);
void init_levels7(level_select_t *levels, sfClock **clock);
int level_picked(sfMouseButtonEvent mouse, level_t *level, window_t *window);
void init_loose_menu(loose_menu_t *loose_menu, window_t *window);
int loose_menu_mouse_event(loose_menu_t *loose_menu, sfMouseButtonEvent mouse,
window_t *window);
int analyse_loose_menu_events(window_t *window);
void loose_menu(window_t *window);
int usage(void);
void init_window2(window_t *window);
void init_window(window_t *window);
int main(int ac, char **av);
int menu_mouse_event(menu_t *menu, sfMouseButtonEvent mouse, window_t *window);
int analyse_menu_events(window_t *window);
void menu(window_t *window);
void menu2(window_t *window);
void menu3(window_t *window);
void menu4(window_t *window);
void init_menu(menu_t *menu, window_t *window);
void init_menu2(menu_t *menu, window_t *window);
void init_menu3(menu_t *menu, window_t *window);
int menu_mouse_event2(menu_t *menu, sfMouseButtonEvent mouse,
window_t *window);
int menu_mouse_event3(menu_t *menu, sfMouseButtonEvent mouse,
window_t *window);
int menu_mouse_event4(menu_t *menu, sfMouseButtonEvent mouse,
window_t *window);
int menu_mouse_event5(menu_t *menu, sfMouseButtonEvent mouse,
window_t *window);
int menu_mouse_event6(menu_t *menu, sfMouseButtonEvent mouse,
window_t *window);
int menu_mouse_event7(menu_t *menu, sfMouseButtonEvent mouse,
window_t *window);
int menu_mouse_event8(menu_t *menu, sfMouseButtonEvent mouse,
window_t *window);
int menu_mouse_event9(menu_t *menu, sfMouseButtonEvent mouse,
window_t *window);
int menu_mouse_event10(menu_t *menu, sfMouseButtonEvent mouse,
window_t *window);
int	my_getnbr(const char *str);
int my_int_len(int n);
char *my_int_to_str(int num);
void my_putstr(char const *str);
int count_word_len(char const *str);
int how_many_words(char const *str);
int str_to_array_loop(char const *str, int i, int j, char **tab);
char **my_str_to_word_array(char const *str);
char *my_strcat(char *dest, char *src);
int my_strlen(char const *str);
void init_pause(pause_t *pause);
int pause_mouse_event(pause_t *pause, sfMouseButtonEvent mouse,
window_t *window);
int analyse_pause_events(window_t *window);
void pause_game(window_t *window);
void init_player(player_t *player);
void create_projectile(projectile_t **list, soldier_info_t soldier_info,
sfClock **clock, int target);
void damages_enemy_at_range(projectile_t *proj, soldiers_t *enemy);
void move_to_enemy(projectile_t *proj, soldiers_t *enemy);
void calc_projectile_position(projectile_t *list, soldiers_t *enemies);
void print_projectiles(projectile_t *list, sfRenderWindow *window,
sfClock **clock);
void delete_projectiles_2(projectile_t **begin, projectile_t *prev,
projectile_t *next, projectile_t *curent);
void delete_used_projectiles(projectile_t **begin);
static int randomize_helper(FILE *in);
int randomize(void);
char *open_file_in_buffer(char const *filepath);
void load_save(player_t *player);
void write_on_save(char *to_save);
void prepare_save(player_t *player);
int calc_tower_sprite(shop_item_t *tower, sfMouseButtonEvent mouse, int lvl,
window_t *window);
int shop_mouse_event(shop_t *shop, sfMouseButtonEvent mouse, window_t *window);
int analyse_level_shop(window_t *window);
void display_item(window_t *window, shop_item_t *item, int lvl);
void shop(window_t *window);
void init_item(shop_item_t *item, int *prices, int level, sprite_info_t info);
void init_shop(shop_t *shop, window_t *window);
void init_shop2(shop_t *shop, window_t *window);
void add_soldier(soldier_info_t soldier_info, soldiers_t **list,
sfClock **clock);
void print_soldiers(soldiers_t *list, sfRenderWindow *window, sfClock **clock);
void delete2(soldiers_t **begin, soldiers_t *prev, soldiers_t *next,
soldiers_t *curent);
void delete_dead_soldiers(soldiers_t **begin);
sprite_t init_sprite(sprite_info_t sprite_i);
void animate_soldier(soldiers_t *soldier, sfClock **clock,
sfRenderWindow *window, sprite_t *sprite);
void animate_health_bar(soldiers_t *soldier, sfRenderWindow *window);
void button_hover_simple_animation(sfVector2i mouse, sprite_t *button);
void button_hover_color_animation(sfVector2i mouse, sprite_t *button);
void init_text(text_t *text, int size, char *str, sfVector2f pos);
void init_circle(circle_t *circle, sfVector2f pos, float radius);
void sound_set_audio(sfSound **sound, char *path, int volume);
void music_set_audio(sfMusic **music, char *path, int volume);
int is_closest(sfVector2f pos, sfVector2f v1, sfVector2f v2);
sfVector2f change_closest(sfVector2f pos, sfVector2f prev_closest,
sfVector2f to_compare, int exists);
void soldier_target(soldiers_t *attacant, team_t *target, sfClock **clock);
int inflict_damage_on_buildings(soldiers_t *attacant, team_t *target,
sfFloatRect attacant_box);
int inflict_damage(soldiers_t *attacant, team_t *target);
void attack(soldiers_t *attacant, team_t *target, sfClock **clock);
void soldier_action(soldiers_t *attacant, team_t *target, sfVector2f closest,
sfClock **clock);
int is_building_at_range(soldiers_t *attacant, team_t *target);
int is_at_range(soldiers_t *attacant, team_t *target);
void move_to_closest(soldiers_t *attacant, sfVector2f closest);
void init_win_menu(win_menu_t *win_menu, window_t *window);
int win_menu_mouse_event(win_menu_t *win_menu, sfMouseButtonEvent mouse,
window_t *window);
int analyse_win_menu_events(window_t *window);
void win_menu(window_t *window);
void win_menu2(window_t *window);


#endif /* !INCLUDE_H_ */
