/*
** EPITECH PROJECT, 2022
** my_malloc
** File description:
** malloc
*/

#include "malloc.h"

memory_block_t memory = NULL;

memory_block_t find_block(memory_block_t *prev, size_t size)
{
    memory_block_t best = NULL;

    for (memory_block_t temp = memory; temp; temp = temp->next) {
        if (temp->free && temp->size >= size && best == NULL)
            best = temp;
        else if (temp->free && temp->size >= size && temp->size < best->size)
            best = temp;
    }
    if (best)
        *prev = best->prev;
    return (best);
}

memory_block_t extend_heap(memory_block_t prev, size_t size)
{
    memory_block_t temp;
    size_t page_size = getpagesize() * 2;

    temp = sbrk(0);
    while (page_size < (BLOCK_SIZE + size))
        page_size += getpagesize() * 2;
    if (sbrk(page_size) < 0)
        return (NULL);
    temp->free = 0;
    temp->size = page_size;
    temp->next = NULL;
    temp->prev = prev;
    temp->ptr = temp->data;
    if (prev) {
        prev->next = temp;
    }
    return (temp);
}

void split_block(memory_block_t temp, size_t size)
{
    memory_block_t new;
    new = (memory_block_t)(temp->data + size);
    new->size = temp->size - size - BLOCK_SIZE;
    new->next = temp->next;
    new->prev = temp;
    new->free = 1;
    new->ptr = new->data;
    temp->size = size;
    temp->next = new;
    if (new->next)
        new->next->prev = new;
}

void *malloc(size_t size)
{
    memory_block_t temp;
    memory_block_t prev = NULL;
    size_t s = alignpower2(size);

    prev = memory;
    temp = find_block(&prev, s);
    if (temp) {
        if ((temp->size - s) >= (BLOCK_SIZE + 4))
            split_block(temp, s);
        temp->free = 0;
    } else {
        temp = extend_heap(prev, s);
        if (!temp)
            return (NULL);
    }
    if (!memory) {
        memory = temp;
    }
    return (temp->data);
}