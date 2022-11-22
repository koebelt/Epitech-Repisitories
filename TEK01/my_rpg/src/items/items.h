    /*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** items
*/

#ifndef ITEMS_H_
#define ITEMS_H_

#include "../../include/include.h"

#define LEGS1 "assets/objects/legs.png"
#define LEGS2 "assets/objects/legs2.png"
#define FEET1 "assets/objects/feets.png"
#define FEET2 "assets/objects/feets2.png"
#define HEAD1 "assets/objects/head.png"
#define HEAD2 "assets/objects/head2.png"
#define ARMOR1 "assets/objects/armor.png"
#define ARMOR2 "assets/objects/armor2.png"
#define ARMS1 "assets/objects/arms.png"
#define ARMS2 "assets/objects/arms2.png"
#define DAMAGE_BOOK "assets/objects/damage_book.png"
#define DAMAGE_RUNE "assets/objects/damage_rune.png"
#define DAMAGE_RING "assets/objects/damage_ring.png"
#define ARMOR_BOOK "assets/objects/armor_book.png"
#define ARMOR_RUNE "assets/objects/armor_rune.png"
#define ARMOR_RING "assets/objects/armor_ring.png"
#define ATTACK_SPEED_BOOK "assets/objects/attack_speed_book.png"
#define ATTACK_SPEED_RUNE "assets/objects/attack_speed_rune.png"
#define ATTACK_SPEED_RING "assets/objects/attack_speed_ring.png"
#define SPEED_BOOK "assets/objects/speed_book.png"
#define SPEED_RUNE "assets/objects/speed_rune.png"
#define SPEED_RING "assets/objects/speed_ring.png"


void print_items(window_t *window);
void handle_item(window_t *window, item_t **item);
void mouse_and_items(window_t *window);
void replace_item(window_t *window, item_t **item);
void destroy_items(window_t *window);
void get_rand_item(window_t *window);

#endif /* !ITEMS_H_ */
