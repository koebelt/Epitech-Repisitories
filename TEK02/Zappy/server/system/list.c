/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** list
*/

#include "../server.h"
#include "./new.h"

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Create a packet that contain data
** @param data (char*): Data to add
**
** @return new packet with data
**/
t_packet *create_packet_element(char *data)
{
    t_packet *element = malloc(sizeof(t_packet));
    element->object = new(Packet, strdup(data), strlen(data));
    return (element);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Function *create_packet_short: Create a a packet with a simple
** data in one line
** @param listpacket (struct): The list of target packets
** @param data (char*): The data to add inside packet
**
** @return if packet been successfuly created or not
**/
int create_packet_short(struct listpacket *list, char *data)
{
    t_packet *packet = create_packet_element(data);

    if (!packet)
        return (0);
    TAILQ_INSERT_TAIL(list, packet, entries);
    return (1);
}