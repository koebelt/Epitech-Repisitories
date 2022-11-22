/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** map
*/

#include "../objects/command.h"
#include "../server.h"

/**
** @author : Paul Gazeau-Rousseau
**
** @command msz
** @executor GUI_USER
**
** @brief Get size of map
** @param this (t_command*): The command that been executed
** @param client (ClientClass*): Client that has execute command
** @param server (ServerClass*): Pointer on server
**
** @return int
**/
int command_msz(t_command *this, ClientClass *client,
ServerClass *server)
{
    char *strd = NULL;
    char *gui_message = NULL;

    if (this && this->nb_args != 0)
        return (0);
    asprintf(&strd, "msz %s", str(server->map->size));
    AddPacket(strd);
    return (1);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @command bct X Y - where X and Y is the coordinate of the tile
** @executor GUI_USER
**
** @brief Give the current info of a specific tile
** @param this (t_command*): The command that been executed
** @param client (ClientClass*): Client that has execute command
** @param server (ServerClass*): Pointer on server
**
** @return int
**/
int command_bct(t_command *this, ClientClass *client,
ServerClass *server)
{
    char *strd = NULL;
    TileClass *tile = NULL;

    if (this && this->nb_args != 2)
        return (0);
    if ((tile = Map_getTile(server->map, atoi(this->args[0]),
    atoi(this->args[1]))))
        return (0);
    asprintf(&strd, "bct %s", str(tile));
    Team_Broadcast(get_team(server, GRAPHIC_TEAM), strd);
    return (1);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @command mct
** @executor GUI_USER
**
** @brief Give the current info of all ths tiles
** @param this (t_command*): The command that been executed
** @param client (ClientClass*): Client that has execute command
** @param server (ServerClass*): Pointer on server
**
** @return int
**/
int command_mct(t_command *this, ClientClass *client,
ServerClass *server)
{
    char *strd = NULL;

    if (this && this->nb_args != 0)
        return (0);
    for (t_tile *np = server->map->thead.tqh_first; np; np =
    np->entries.tqe_next) {
        strd = NULL;
        asprintf(&strd, "bct %s", str(np->object));
        Team_Broadcast(get_team(server, GRAPHIC_TEAM), strd);
        free(strd);
    }
    return (1);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @command tna
** @executor GUI_USER
**
** @brief Give the current info about all the teams
** @param this (t_command*): The command that been executed
** @param client (ClientClass*): Client that has execute command
** @param server (ServerClass*): Pointer on server
**
** @return int
**/
int command_tna(t_command *this, ClientClass *client,
ServerClass *server)
{
    char *strd = NULL;

    if (this && this->nb_args != 0)
        return (0);
    for (t_team *np = server->thead.tqh_first; np != NULL; np =
    np->entries.tqe_next) {
        strd = NULL;
        asprintf(&strd, "tna %s", np->object->name);
        AddPacket(strd);
        free(strd);
    }
    return (1);
}