/*
** EPITECH PROJECT, 2022
** server
** File description:
** player
*/

#include "../objects/command.h"
#include "../server.h"

/**
** @author : Paul Gazeau-Rousseau
**
** @command ppo n - where n is the id of a player
** @executor GUI_USER
**
** @brief Return position of a player
** @param this (t_command*): The command that been executed
** @param client (ClientClass*): Client that has execute command
** @param server (ServerClass*): Pointer on server
**
** @return int
**/
int command_ppo(t_command *this, ClientClass *client, ServerClass *server)
{
    char *strd = NULL;
    ClientClass *current = NULL;

    if (this->nb_args != 1)
        return (0);
    if (!(current = Server_getClient(server, atoi(this->args[0]))))
        return (0);
    asprintf(&strd, "ppo %d %s %d", current->id,
    str(current->player->position), current->player->eye_direction);
    AddPacket(strd);
    return (1);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @command plv n - where n is the id of a player
** @executor GUI_USER
**
** @brief Return level of a player
** @param this (t_command*): The command that been executed
** @param client (ClientClass*): Client that has execute command
** @param server (ServerClass*): Pointer on server
**
** @return int
**/
int command_plv(t_command *this, ClientClass *client, ServerClass *server)
{
    char *strd = NULL;
    ClientClass *current = NULL;

    if (this->nb_args != 1)
        return (0);
    if (!(current = Server_getClient(server, atoi(this->args[0]))))
        return (0);
    asprintf(&strd, "plv %d %d", current->id, current->player->level);
    AddPacket(strd);
    return (1);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @command pin n - where n is the id of a player
** @executor GUI_USER
**
** @brief Return inventory of a player
** @param this (t_command*): The command that been executed
** @param client (ClientClass*): Client that has execute command
** @param server (ServerClass*): Pointer on server
**
** @return int
**/
int command_pin(t_command *this, ClientClass *client, ServerClass *server)
{
    char *strd = NULL;
    ClientClass *current = NULL;

    if (this->nb_args != 1)
        return (0);
    if (!(current = Server_getClient(server, atoi(this->args[0]))))
        return (0);
    asprintf(&strd, "pin %d %s %s", current->id,
    str(current->player->position), str(current->player->inventory));
    AddPacket(strd);
    return (1);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @command inventory
** @executor IA_USER
**
** @brief Return inventory of the player
** @param this (t_command*): The command that been executed
** @param client (ClientClass*): Client that has execute command
** @param server (ServerClass*): Pointer on server
**
** @return int
**/
int command_inventory(t_command *this, ClientClass *client,
ServerClass *server)
{
    char *str = NULL;
    char *gui_message = NULL;

    if (this->nb_args != 0)
        return (0);
    AddPacket(inventory_display(client->player->inventory));
    return (1);
}