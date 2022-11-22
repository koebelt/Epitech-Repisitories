/*
** EPITECH PROJECT, 2022
** server
** File description:
** look
*/

#include "../objects/command.h"
#include "../server.h"
#include "../includes/prerequisite.h"

static void ledeuxiemeifduq(char **buffer, int count)
{
    if (count > 0)
        *buffer = my_strcat(*buffer, " ");
}

static void command_look_next(ServerClass *server, VectorClass *vector,
char **buffer)
{
    int count = 0;
    TileClass *tile = NULL;
    VectorClass *mapSize = server->map->size;

    printf("before -> pos x = %d and y = %d\n", vector->x, vector->y);
    if (vector->x < 0)
        vector->x = mapSize->x - 1;
    if (vector->y < 0)
        vector->y = mapSize->y - 1;
    if (vector->x >= mapSize->x)
        vector->x = 0;
    if (vector->y >= mapSize->y)
        vector->y = 0;
    printf("after -> pos x = %d and y = %d\n", vector->x, vector->y);
    tile = Map_getTile(server->map, vector->x, vector->y);
    if (!tile)
        return;
    printf("buffer start : (%s)\n", *buffer);
    for (t_tplayer *np = tile->tphead.tqh_first; np != NULL; np =
    np->entries.tqe_next, count++) {
        if (!np->object)
            continue;
        *buffer = my_strcat(*buffer, "player");
        if (count > 0)
            *buffer = my_strcat(*buffer, " ");
    }
    printf("buffer middle : (%s)\n", *buffer);
    for (int i = 0; i < 7; i++) {
        for (int q = tile->ressource[i].quantity; q > 0; q--, count++) {
            ledeuxiemeifduq(buffer, count);
            *buffer = my_strcat(*buffer, tile->ressource[i].name);
        }
    }
    printf("buffer end : (%s)\n", *buffer);
}

static void leifduq(int r, int i, char **buffer)
{
    if (!(r == -i && i == 0))
        *buffer = my_strcat(*buffer, ",");
}

/**
** @author : Tristan Courty & Thomas Koebel
**
** @command Look
** @executor IA_USER
**
** @brief Run when ia want to look forward want it's placed on tiles
** @param this (t_command*): The command that been executed
** @param client (ClientClass*): Client that has execute command
** @param server (ServerClass*): Pointer on server
**
** @return int
**/
int command_look(t_command *this, ClientClass *client,
ServerClass *server)
{
    char *buffer = strdup("[");
    char *gui_message = NULL;
    VectorClass *pos = NULL;
    TileClass *tile = NULL;

    for (int i = 0; i <= client->player->level; i++) {
        for (int r = -i; r <= i; r++) {
            leifduq(r, i, &buffer);
            switch (client->player->eye_direction) {
                case 1:
                    printf("nord\n");
                    printf("pPos (x : %d - y : %d)\n", PosX, PosY);
                    printf("new vec (x : %d - y : %d)\n",((VectorClass *) new(Vector, r, -i))->x, ((VectorClass *) new(Vector, r, -i))->y);
                    command_look_next(server, addition(new(Vector, PosX, PosY), new(Vector, r, -i)), &buffer);
                    break;
                case 2:
                    printf("est\n");
                    command_look_next(server, addition(new(Vector, PosX, PosY), new(Vector, i, r)), &buffer);
                    break;
                case 3:
                    printf("sud\n");
                    command_look_next(server, addition(new(Vector, PosX, PosY), new(Vector, r, i)), &buffer);
                    break;
                case 4:
                    printf("ouest\n");
                    command_look_next(server, addition(new(Vector, PosX, PosY), new(Vector, -i, r)), &buffer);
                    break;
            }
        }
    }
    buffer = my_strcat(buffer, "]");
    printf("buffer look : (%s)\n", buffer);
    AddPacket(buffer);
    return (1);
}