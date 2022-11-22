/*
** EPITECH PROJECT, 2022
** server
** File description:
** time
*/

#include "../objects/command.h"
#include "../server.h"

/**
** @author : Paul Gazeau-Rousseau
**
** @command sgt
** @executor GUI_USER
**
** @brief Give the current time unit
** @param this (t_command*): The command that been executed
** @param client (ClientClass*): Client that has execute command
** @param server (ServerClass*): Pointer on server
**
** @return int
**/
int command_sgt(t_command *this, ClientClass *client, ServerClass *server)
{
    char *strd = NULL;

    if (this && this->nb_args != 0)
        return (0);
    asprintf(&strd, "sgt %d", server->time_unit);
    AddPacket(strd);
    return (1);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @command sst T - where t is the new time unit
** @executor GUI_USER
**
** @brief Give the current time unit
** @param this (t_command*): The command that been executed
** @param client (ClientClass*): Client that has execute command
** @param server (ServerClass*): Pointer on server
**
** @return int
**/
int command_sst(t_command *this, ClientClass *client, ServerClass *server)
{
    char *strd = NULL;

    if (this->nb_args != 1)
        return (0);
    server->time_unit = atoi(this->args[0]);
    if (!server->time_unit)
        return (0);
    asprintf(&strd, "sst %d", server->time_unit);
    AddPacket(strd);
    return (1);
}