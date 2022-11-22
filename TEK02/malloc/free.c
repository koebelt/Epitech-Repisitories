/*
** EPITECH PROJECT, 2022
** B-PSU-400-STG-4-1-malloc-thomas.koebel
** File description:
** free
*/

#include "malloc.h"

memory_block_t get_block(void *p)
{
    memory_block_t tmp = memory;

    while (tmp != NULL) {
        if (tmp->ptr == p) {
            return (tmp);
        }
        tmp = tmp->next;
    }
    return (NULL);
}

int valid_address(void *p)
{
    if (memory && p)
        if (p > (void *)memory && p < sbrk(0))
            return (get_block(p) != NULL);
    return (0);
}

memory_block_t fusion(memory_block_t temp)
{
    if (temp->next && temp->next->free) {
        temp->size += BLOCK_SIZE + temp->next->size;
        temp->next = temp->next->next;
        if (temp->next)
            temp->next->prev = temp;
    }
    return (temp);
}

void reduce_heap(memory_block_t temp)
{
    if (temp->prev)
        temp->prev->next = NULL;
    else
        memory = NULL;
    sbrk(-(temp->size + BLOCK_SIZE));
}

void free(void *p)
{
    memory_block_t temp;

    if (!valid_address(p))
        return;
    temp = get_block(p);
    temp->free = 1;
    if (temp->prev && temp->prev->free)
        temp = fusion(temp->prev);
    if (temp->next && temp->next->free)
        fusion(temp);
    else if (!temp->next) {
        reduce_heap(temp);
    }
}