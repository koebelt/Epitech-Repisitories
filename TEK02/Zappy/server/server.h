/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** player
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #define _GNU_SOURCE
    #include <stdio.h>

    #include "./system/object.h"
    #include "./includes/list.h"
    #include "./includes/prerequisite.h"
    #include "./objects/player.h"
    #include "./objects/team.h"
    #include "./objects/zappy_map.h"
    #include "./packets/packet.h"
    #include "./objects/event.h"
    #include "./objects/logger.h"

    #define GRAPHIC_TEAM "GRAPHIC"
    #define TINSERT(l, o) TAILQ_INSERT_TAIL(l, create_packet_element(o),\
    entries);

TAIL_HEAD_OF(listentry, s_entry);

typedef TAIL_OF(s_entry, char, t_entry);

TAIL_HEAD_OF(listcmd, s_commandl)
TAIL_HEAD_OF(listpacket, s_packet);

typedef struct {
    Class base;
    int socket;
    int ssocket; // Server socket
    char *saved_cmd;
    struct sockaddr_in address;
    struct listcmd chead;
    PlayerClass *player;
    TeamClass *team;
    int id;
    struct listpacket phead;
    TAIL_OF(s_packet, PacketClass, packets);
    TAIL_OF(s_commandl, void, commands);
}   ClientClass;

typedef struct s_packet t_packet;
typedef struct s_commandl t_commandl;

void client_ctor(ClientClass *this, va_list *args);
void client_dtor(ClientClass *this);
void client_init(ClientClass *this, fd_set *rset, fd_set *wset);
void client_add_delay_command(ClientClass *this, const char *name, int ti);
struct listentry *client_read(ClientClass *this);
void client_write(ClientClass *this, Object *server);

int process_command(ClientClass *client, Object *server);
bool client_can_eat(ClientClass *this, Object *server);

static const ClientClass _clientdescription = {
    {
        .__size__ = sizeof(ClientClass),
        .__name__ = "Client",
        .__ctor__ = (ctor_t)&client_ctor,
        .__dtor__ = (dtor_t)&client_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL,
        .__functions__ = {
            client_init,
            client_read,
            client_write,
            client_can_eat,
            process_command
        }
    },
    .socket = 0,
    .ssocket = 0,
    .saved_cmd = NULL,
    .address = {0},
    .player = NULL,
    .phead = {0},
    .team = NULL,
    .id = 0,
    .packets = NULL,
    .commands = NULL
};

static const Class *Client = (const Class *)&_clientdescription;

    #define Client_init(o, r, w) ((int (*)(ClientClass *, fd_set *, \
    fd_set *)) find(o, 0))(o, r, w)
    #define Client_read(o) ((struct listentry *(*)(ClientClass *)) \
    find(o, 1))(o)
    #define Client_write(o, s) ((void (*)(ClientClass *, Object *)) find(o, 2))(o, s)
    #define Client_canEat(o, s) ((bool (*)(ClientClass *, ServerClass *)) \
    find(o, 3))(o, s)
    #define Client_processCommand(c, s) ((int (*)(ClientClass *, Object *)) \
    find(c, 4))(c, s)

TAIL_HEAD_OF(listteam, s_team)
LIST_HEAD_OF(listclient, s_client)

typedef struct {
    Class base;
    int port;
    int socket;
    ZappyMapClass *map;
    struct listclient head;
    struct listteam thead;
    int max_players_team;
    Ressource max_ressources[7];
    int time_unit;
    int time;
    LoggerClass *logs[3];
    TAIL_OF(s_team, TeamClass, teams);
    LIST_OF(s_client, ClientClass, clients);
    bool open;
} ServerClass;

typedef struct s_client t_client;
typedef struct s_team t_team;

ClientClass *get_client(ServerClass *this, int id);
void generation_ressources(ServerClass *server);
void server_ctor(ServerClass *this, va_list *args);
void server_start(ServerClass *this);
void server_dtor(ServerClass *this);
void server_add_team(ServerClass *this, const char *name, int level);
void server_create_map(ServerClass *this, int width, int height);
void server_set_time_unit(ServerClass *this, int time);

t_packet *create_packet_element(char *data);
int create_packet_short(struct listpacket *list, char *data);

TeamClass *get_team(ServerClass* this, const char *name);

//Packets
void team_packet(ServerClass *this, ClientClass *client, TeamClass *self);
void team_packet_second(ServerClass *this, ClientClass *client, TeamClass *);
void tile_packet(ServerClass *this, ClientClass *client, TileClass *tile);
void map_packet(ServerClass *this, ClientClass *client, ZappyMapClass *map);
int check_team_victory(TeamClass *team, ServerClass *server);
void event_manager(ClientClass *client, ServerClass *server);

static const ServerClass _serverdescription = {
    {
        .__size__ = sizeof(ServerClass),
        .__name__ = "Server",
        .__ctor__ = (ctor_t)&server_ctor,
        .__dtor__ = (dtor_t)&server_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL,
        .__functions__ = {
            server_start,
            server_add_team,
            server_create_map,
            team_packet,
            server_set_time_unit,
            generation_ressources,
            get_client,
            check_team_victory,
            event_manager
        }
    },
    .port = 0,
    .socket = 0,
    .map = NULL,
    .head = {0},
    .thead = {0},
    .max_players_team = 0,
    .max_ressources = {0},
    .time_unit = 100,
    .time = 0,
    .teams = NULL,
    .clients = NULL,
    .open = true,
    .logs = NULL
};

static const Class *Server = (const Class *)&_serverdescription;

    #define Server_start(o) ((void (*)(ServerClass *)) find(o, 0))(o)
    #define Server_addTeam(o, n, l) ((void (*)(ServerClass *, const char *, \
    int)) find(o, 1))(o, n, l)
    #define Server_createMap(o, w, h) ((void (*)(ServerClass *, int, int)) \
    find(o, 2))(o, w, h)
    #define Team_packet(s, c, t)  ((void (*)(ServerClass *, ClientClass *, \
    TeamClass *)) find(s, 3))(s, c, t)
    #define Server_setTimeUnit(s, t)  ((void (*)(ServerClass *, int)) \
    find(s, 4))(s, t)
    #define Generation_start(s) ((void (*)(ServerClass *)) find(s, 5))(s)
    #define Server_getClient(s, id) ((ClientClass *(*)(ServerClass *, int)) \
    find(s, 6))(s, id)
    #define Server_Victory(t, s) ((int (*)(TeamClass *, ServerClass *)) \
    find(s, 7))(t, s)
    #define EventManager_handle(c, s) ((void (*)(ClientClass *, ServerClass \
    *)) find(s, 8))(c, s)

#endif /* !SERVER_H_ */
