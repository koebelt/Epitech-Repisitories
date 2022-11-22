/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #define _GNU_SOURCE

    #include "../system/object.h"
    #include "./inventory.h"
    #include "../includes/prerequisite.h"

    #define PosX ((VectorClass *)client->player->position)->x
    #define PosY ((VectorClass *)client->player->position)->y

typedef struct {
    Class base;
    Object *position;
    int level;
    int food;
    enum direction {
        NORTH = 1,
        EST = 2,
        SOUTH = 3,
        WEST = 4
    } eye_direction;
    InventoryClass *inventory;
    Object *team;
    Object *client;
    bool dead;
    bool incantation;
    int egg_id;
} PlayerClass;

void player_ctor(PlayerClass *this, va_list *args);
void player_dtor(PlayerClass *this);
char *player_str(PlayerClass *obj);
Object *player_get_vision(PlayerClass *this);
void player_eat(PlayerClass *this, Object *server);

static const PlayerClass _playerdescription = {
    {
        .__size__ = sizeof(PlayerClass),
        .__name__ = "Player",
        .__ctor__ = (ctor_t)&player_ctor,
        .__dtor__ = (dtor_t)&player_dtor,
        .__str__ = (to_string_t)&player_str,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL,
        .__functions__ = {
            player_get_vision,
            player_eat
        }
    },
    .position = NULL,
    .level = 1,
    .food = 0,
    .eye_direction = 1,
    .inventory = NULL,
    .team = NULL,
    .client = NULL,
    .dead = false,
    .egg_id = 0
};

static const Class *Player = (const Class *)&_playerdescription;

    #define Player_getVision(o) ((Object *(*)(PlayerClass *)) find(o, 0))(o)
    #define Player_eat(o, s) ((void (*)(PlayerClass *, ServerClass *))\
    find(o, 0))(o, s)

#endif /* !PLAYER_H_ */
