/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** team
*/

#include "./server.h"
#include "./system/new.h"

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Constructor for Server Class
** @param this (ServerClass*): Pointer on class
** @param args (va_list*): list of argument given by new
**
** @return Nothing
**/
void server_ctor(ServerClass *this, va_list *args)
{
    struct stat info = {0};
    struct sockaddr_in addr = {0};

    LIST_INIT(&this->head);
    TAILQ_INIT(&this->thead);
    this->port = va_arg(*args, int);
    if (this->port < 1024 || this->port > 65535)
        raise("Invalid port number");
    addr = (struct sockaddr_in ) {
        .sin_family = AF_INET, .sin_port = htons(this->port),
        .sin_addr.s_addr = htonl(INADDR_ANY)
    };
    if ((this->socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        raise("Error (server.c): Socket is invalid");
    if (bind(this->socket, (struct sockaddr *) &addr, sizeof(addr)) != 0)
        raise("Error (server.c): Cannot bind the server");
    if (listen(this->socket, 5) != 0)
        raise("Error (server.c): Cannot start listening");
    printf("Server start listening on port: %d\n", this->port);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Destructor for Server Class
** @param this (ServerClass*): Pointer on class
**
** @return Nothing
**/
void server_dtor(ServerClass *this)
{
    if (this->map)
        delete(this->map);
    while (this->thead.tqh_first != NULL) {
        delete(this->thead.tqh_first->object);
        TAILQ_REMOVE(&this->thead, this->thead.tqh_first, entries);
    }
    while (this->head.lh_first != NULL) {
        delete(this->head.lh_first->object);
        LIST_REMOVE(this->head.lh_first, entries);
    }
    printf("Server stop listening on port: %d\n", this->port);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Function server_add_team: Add a new team into server
** @param this (ServerClass*): Pointer on class
** @param char (const): Name of team
** @param level (int): Level of team
**
** @return Nothing
**/
void server_add_team(ServerClass *this, const char *name, int level)
{
    t_team *team = malloc(sizeof(t_team));
    team->object = new(Team, name, level);
    TAILQ_INSERT_TAIL(&this->thead, team, entries);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Function server_create_map: Create Map for server
** @param this (ServerClass*): Pointer on class
** @param width (int): WIdth of the map
** @param height (int): Height of the map
**
** @return Nothing
**/
void server_create_map(ServerClass *this, int width, int height)
{
    this->map = (ZappyMapClass *) new(ZappyMap, width, height);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Function server_set_time_unit: Modify time unit used by the server
** @param this (ServerClass*): Pointer on class
** @param time (int): Time unit desired
**
** @return Nothing
**/
void server_set_time_unit(ServerClass *this, int time)
{
    this->time_unit = time;
}