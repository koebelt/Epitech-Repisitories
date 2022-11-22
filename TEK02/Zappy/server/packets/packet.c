/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** packet
*/

#include "./packet.h"
#include "../system/new.h"

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Constructor for Team Class
** @param this (TeamClass*): Pointer on class
** @param args (va_list*): list of argument given by new
**
** @return Nothing
**/
void packet_ctor(PacketClass *this, va_list *args)
{
    this->data = va_arg(*args, char*);
    this->size = va_arg(*args, int);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Destructor for Packet Class
** @param this (PlayerClass*): Pointer on class
**
** @return Nothing
**/
void packet_dtor(PacketClass *this)
{
    free(this->data);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Function packet_write: Write a packet on socket
** @param this (PacketClass*): Packet to write
** @param fd (int): Socket to write into
**
** @return Nothing
**/
void packet_write(PacketClass *this, int fd)
{
    if (!this->data)
        return;
    printf("%.*s\n", this->size, this->data);
    dprintf(fd, "%.*s\n", this->size, this->data);
}