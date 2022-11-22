/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** zappymap
*/

#ifndef ZAPPYMAP_H_
    #define ZAPPYMAP_H_

    #define _GNU_SOURCE

    #include "../includes/list.h"
    #include "../system/object.h"
    #include "./player.h"
    #include "./ressource.h"
    #include "./vector.h"
    #include <sys/queue.h>
    #include <stdlib.h>

TAIL_HEAD_OF(listtplayers, s_tplayer);

typedef struct {
    Class base;
    VectorClass *pos;
    Ressource ressource[7];
    struct listtplayers tphead;
    TAIL_OF(s_tplayer, PlayerClass, players);
    void *map;
} TileClass;

typedef struct s_tplayer t_tplayer;

void tile_ctor(TileClass *this, va_list *args);
void tile_dtor(TileClass *this);
char *tile_str(TileClass *this);

void tile_add_ressource(TileClass *this, RessourceType type);

void tile_add_player(TileClass *this, PlayerClass *player);
void tile_remove_player(TileClass *this, PlayerClass *player);

static const TileClass _tiledescription = {
    {
        .__size__ = sizeof(TileClass),
        .__name__ = "Tile",
        .__ctor__ = (ctor_t)&tile_ctor,
        .__dtor__ = (dtor_t)&tile_dtor,
        .__str__ = (to_string_t)&tile_str,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL,
        .__functions__ = {
            tile_add_ressource,
            tile_add_player,
            tile_remove_player
        }
    },
    .pos = NULL,
    .ressource = {0},
    .tphead = {0},
    .players = NULL,
    .map = NULL
};

static const Class *Tile = (const Class *)&_tiledescription;

    #define Tile_addRessource(o, r) ((void (*)(TileClass *, RessourceType)) \
    find(o, 0))(o, r)
    #define Tile_addPlayer(o, p) ((void (*)(TileClass *, PlayerClass *)) \
    find(o, 1))(o, p)
    #define Tile_removePlayer(o, p) ((void (*)(TileClass *, PlayerClass *)) \
    find(o, 2))(o, p)

TAIL_HEAD_OF(listtile, s_tile);

typedef struct {
    Class base;
    VectorClass *size;
    struct listtile thead;
    TAIL_OF(s_tile, TileClass, tiles);
} ZappyMapClass;

typedef struct s_tile t_tile;

void zappymap_ctor(ZappyMapClass *this, va_list *args);
void zappymap_dtor(ZappyMapClass *this);

char *zappymap_str(ZappyMapClass *this);

TileClass *get_tile_at_pos(ZappyMapClass *this, int posX, int posY);

static const ZappyMapClass _zappymapdescription = {
    {
        .__size__ = sizeof(ZappyMapClass),
        .__name__ = "ZappyMap",
        .__ctor__ = (ctor_t)&zappymap_ctor,
        .__dtor__ = (dtor_t)&zappymap_dtor,
        .__str__ = (to_string_t)&zappymap_str,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL,
        .__functions__ = {
            get_tile_at_pos
        }
    },
    .size = NULL,
    .thead = {0},
    .tiles = NULL
};

static const Class *ZappyMap = (const Class *)&_zappymapdescription;

    #define Map_getTile(o, x, y) ((TileClass *(*)(ZappyMapClass *, int, int)) \
    find(o, 0))(o, x, y)

#endif /* !ZAPPYMAP_H_ */
