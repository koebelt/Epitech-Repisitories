/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** zappymap
*/

#ifndef PACKET_H_
    #define PACKET_H_

    #define _GNU_SOURCE

    #include "../includes/list.h"
    #include "../system/object.h"
    #include <sys/queue.h>
    #include <stdlib.h>
    #include <unistd.h>

typedef struct {
    Class base;
    int size;
    char *data;
} PacketClass;

void packet_ctor(PacketClass *this, va_list *args);
void packet_dtor(PacketClass *this);

void packet_write(PacketClass *this, int fd);

static const PacketClass _packetdescription = {
    {
        .__size__ = sizeof(PacketClass),
        .__name__ = "Packet",
        .__ctor__ = (ctor_t)&packet_ctor,
        .__dtor__ = (dtor_t)&packet_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL,
        .__functions__ = {
            packet_write
        }
    },
    .size = 0,
    .data = NULL
};

static const Class *Packet = (const Class *)&_packetdescription;

    #define Packet_write(o, fd) ((int (*)(PacketClass *, int))\
    find(o, 0))(o, fd)
    #define AddPacket(d) create_packet_short(&client->phead, d)
    #define AddPacketC(c, d) create_packet_short(&c->phead, d)

#endif /* !PACKET_H_ */
