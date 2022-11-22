/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace) [WSL : Ubuntu]
** File description:
** event
*/

#include "event.h"
#include "command.h"

void event_manager(ClientClass *client, ServerClass *server)
{
    if (Client_canEat(client, server))
        Player_eat(client->player, server);
    Client_processCommand(client, server);
    //command_mct(NULL, client, server);
    /*if (client && Team_victory(client->team))
        Server_Victory(client->team, server);*/
}