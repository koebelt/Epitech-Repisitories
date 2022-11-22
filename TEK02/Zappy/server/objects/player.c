/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** team
*/

#include "./player.h"
#include "./vector.h"
#include "../server.h"
#include "../system/new.h"

#include <stdio.h>

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Constructor for Player Class
** @param this (InventoryClass*): Pointer on class
** @param args (va_list*): list of argument given by new
**
** @return Nothing
**/
void player_ctor(PlayerClass *this, va_list *args)
{
    int x = 0;
    int y = 0;

    this->client = va_arg(*args, Object *);
    x = va_arg(*args, int);
    y = va_arg(*args, int);
    this->position = new(Vector, x, y);
    this->inventory = new(Inventory);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Destructor for Player Class
** @param this (PlayerClass*): Pointer on class
**
** @return Nothing
**/
void player_dtor(PlayerClass *this)
{
    this->team = NULL;
    this->client = NULL;
    this->level = 0;
    this->food = 0;
    this->dead = false;
    delete(this->inventory);
    delete(this->position);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Str function for Player Class
** @param this (PlayerClass*): Pointer on class
**
** @return Desired Player has string
**/
char *player_str(PlayerClass *this)
{
    
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Function *player_get_vision: Get a vector linked to direction
** where player is looking into
** @param this (PlayerClass*): Player linked to vision
**
** @return Object
**/
Object *player_get_vision(PlayerClass *this)
{
    switch (this->eye_direction) {
        case 1:
            return (new(Vector, 0, -1));
        case 2:
            return (new(Vector, 1, 0));
        case 3:
            return (new(Vector, 0, 1));
        case 4:
            return (new(Vector, -1, 0));
    }
    return (NULL);
}

/**
** @author : Tristan Courty
**
** @brief Function player_eat: check if the player can eat and eat if it's
** alright, if it's not the case send dead to gui and ia
** @param this (PlayerClass*): pointer on the player
** @param server (ServerClass*): pointer on the server
**
** @return Nothing
**/
void player_eat(PlayerClass *this, Object *server)
{
    char *gui_message = NULL;
    ClientClass *client = NULL;

    if (this->inventory->ressource[FOOD].quantity != 0) {
        this->inventory->ressource[FOOD].quantity--;
        return;
    }
    this->dead = true;
    client = this->client;
    AddPacketC(client, "dead");
    asprintf(&gui_message, "pdi %d", client->id);
    Team_Broadcast(get_team(server, GRAPHIC_TEAM), gui_message);
}