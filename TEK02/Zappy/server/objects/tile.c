/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** tile
*/

#include "./zappy_map.h"
#include "../system/new.h"

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Constructor for Tile Class
** @param this (TileClass*): Pointer on class
** @param args (va_list*): list of argument given by new
**
** @return Nothing
**/
void tile_ctor(TileClass *this, va_list *args)
{
    int width = 0;
    int height = 0;
    int x = va_arg(*args, int);
    int y = va_arg(*args, int);

    TAILQ_INIT(&this->tphead);
    this->pos = new (Vector, x, y);
    this->map = va_arg(*args, ZappyMapClass *);
    memcpy(&this->ressource, &_ressources, sizeof(Ressource) * 7);
    width = ((ZappyMapClass *) this->map)->size->x;
    height = ((ZappyMapClass *) this->map)->size->y;
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Destructor for Tile Class
** @param this (TileClass*): Pointer on class
**
** @return Nothing
**/
void tile_dtor(TileClass *this)
{
    delete(this->pos);
    this->map = NULL;

    while (this->tphead.tqh_first != NULL)
        TAILQ_REMOVE(&this->tphead, this->tphead.tqh_first, entries);
    this->tphead = (struct listtplayers) {0};
    memset(&this->ressource, 0, sizeof(Ressource) * 7);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Add ressource in current tile
** @param this (TileClass*): Pointer on class
** @param type (RessourceType): Ressource to add into tile
**
** @return Nothing
**/
void tile_add_ressource(TileClass *this, RessourceType type)
{
    for (int i = 0; i < 7; i++) {
        if (this->ressource[i].type == type) {
            this->ressource[i].quantity += 1;
            break;
        }
    }
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Str function for Tile Class
** @param this (TileClass*): Pointer on class
**
** @return Desired Tile has string
**/
char *tile_str(TileClass *this)
{
    char *buffer = NULL;

    asprintf(&buffer, "%d %d %d %d %d %d %d %d %d",
        this->pos->x,
        this->pos->y,
        this->ressource[0].quantity,
        this->ressource[1].quantity,
        this->ressource[2].quantity,
        this->ressource[3].quantity,
        this->ressource[4].quantity,
        this->ressource[5].quantity,
        this->ressource[6].quantity
    );
    return (buffer);
}