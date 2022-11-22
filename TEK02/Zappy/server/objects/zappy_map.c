/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** team
*/

#include "./zappy_map.h"
#include "../system/new.h"

#include <stdio.h>

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Constructor for ZappyMap Class
** @param this (ZappyMapClass*): Pointer on class
** @param args (va_list*): list of argument given by new
**
** @return Nothing
**/
void zappymap_ctor(ZappyMapClass *this, va_list *args)
{
    int width = va_arg(*args, int);
    int height = va_arg(*args, int);
    this->size = new(Vector, width, height);

    TAILQ_INIT(&this->thead);
    for (int y = 0; y < this->size->y; y++) {
        for (int x = 0; x < this->size->x; x++) {
            struct s_tile *tile = malloc(sizeof(struct s_tile));
            tile->object = new(Tile, x, y, this);
            TAILQ_INSERT_TAIL(&this->thead, tile, entries);
        }
    }
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Destructor for ZappyMap Class
** @param this (ZappyMapClass*): Pointer on class
**
** @return Nothing
**/
void zappymap_dtor(ZappyMapClass *this)
{
    delete(this->size);

    while (this->thead.tqh_first != NULL) {
        delete(this->thead.tqh_first->object);
        TAILQ_REMOVE(&this->thead, this->thead.tqh_first, entries);
    }
    this->thead = (struct listtile) {0};
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Str function for ZappyMap Class
** @param this (ZappyMapClass*): Pointer on class
**
** @return Desired ZappyMap has string
**/
char *zappymap_str(ZappyMapClass *this)
{
    for (t_tile *tile = this->thead.tqh_first; tile; tile =
    tile->entries.tqe_next)
        printf("Tile : (%s)\n", str(this->thead.tqh_first->object));
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Get a tile at given position
** @param this (ZappyMapClass*): Pointer on class
** @param posX (int): X position to search
** @param posY (int): Y position to search
**
** @return Pointer on tile at position or null
**/
TileClass *get_tile_at_pos(ZappyMapClass *this, int posX, int posY)
{
    for (t_tile *np = this->thead.tqh_first; np != NULL; np =
    np->entries.tqe_next) {
        if (!np->object)
            continue;
        if (np->object->pos->x == posX && np->object->pos->y == posY)
            return (np->object);
    }
    return (NULL);
}
