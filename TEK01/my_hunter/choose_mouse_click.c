/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** choose_mouse_click.c
*/

#include "include.h"

int choose_mouse_click3(sfMouseButtonEvent mouse_pos, choose_obj_t *choose)
{
    if (mouse_pos.x > choose->bottles.bottle4.sprite.pos.x && mouse_pos.x <
    (choose->bottles.bottle4.sprite.pos.x +
    choose->bottles.bottle4.sprite.size_text.x *
    choose->bottles.bottle4.sprite.scale.x) && mouse_pos.y >
    choose->bottles.bottle4.sprite.pos.y && mouse_pos.y <
    (choose->bottles.bottle4.sprite.pos.y +
    choose->bottles.bottle4.sprite.size_text.y *
    choose->bottles.bottle4.sprite.scale.y))
        return (5);
    if (mouse_pos.x > choose->bottles.bottle5.sprite.pos.x && mouse_pos.x <
    (choose->bottles.bottle5.sprite.pos.x +
    choose->bottles.bottle5.sprite.size_text.x *
    choose->bottles.bottle5.sprite.scale.x) && mouse_pos.y >
    choose->bottles.bottle5.sprite.pos.y && mouse_pos.y <
    (choose->bottles.bottle5.sprite.pos.y +
    choose->bottles.bottle5.sprite.size_text.y *
    choose->bottles.bottle5.sprite.scale.y))
        return (6);
    return(0);
}

int choose_mouse_click2(sfMouseButtonEvent mouse_pos, choose_obj_t *choose)
{
    if (mouse_pos.x > choose->bottles.bottle3.sprite.pos.x && mouse_pos.x <
    (choose->bottles.bottle3.sprite.pos.x +
    choose->bottles.bottle3.sprite.size_text.x *
    choose->bottles.bottle3.sprite.scale.x) && mouse_pos.y >
    choose->bottles.bottle3.sprite.pos.y &&mouse_pos.y <
    (choose->bottles.bottle3.sprite.pos.y +
    choose->bottles.bottle3.sprite.size_text.y *
    choose->bottles.bottle3.sprite.scale.y))
        return (4);
    if (mouse_pos.x > choose->bottles.bottle2.sprite.pos.x && mouse_pos.x <
    (choose->bottles.bottle2.sprite.pos.x +
    choose->bottles.bottle2.sprite.size_text.x *
    choose->bottles.bottle2.sprite.scale.x) && mouse_pos.y >
    choose->bottles.bottle2.sprite.pos.y && mouse_pos.y <
    (choose->bottles.bottle2.sprite.pos.y +
    choose->bottles.bottle2.sprite.size_text.y *
    choose->bottles.bottle2.sprite.scale.y))
        return (3);
    return(choose_mouse_click3(mouse_pos, choose));
}

int choose_mouse_click(sfMouseButtonEvent mouse_pos, choose_obj_t *choose)
{
    if (mouse_pos.x > choose->bottles.bottle0.sprite.pos.x && mouse_pos.x <
    (choose->bottles.bottle0.sprite.pos.x +
    choose->bottles.bottle0.sprite.size_text.x *
    choose->bottles.bottle0.sprite.scale.x) && mouse_pos.y >
    choose->bottles.bottle0.sprite.pos.y && mouse_pos.y <
    (choose->bottles.bottle0.sprite.pos.y +
    choose->bottles.bottle0.sprite.size_text.y *
    choose->bottles.bottle0.sprite.scale.y))
        return (1);
    if (mouse_pos.x > choose->bottles.bottle1.sprite.pos.x && mouse_pos.x <
    (choose->bottles.bottle1.sprite.pos.x +
    choose->bottles.bottle1.sprite.size_text.x *
    choose->bottles.bottle1.sprite.scale.x) && mouse_pos.y >
    choose->bottles.bottle1.sprite.pos.y && mouse_pos.y <
    (choose->bottles.bottle1.sprite.pos.y +
    choose->bottles.bottle1.sprite.size_text.y *
    choose->bottles.bottle1.sprite.scale.y))
        return (2);
    return(choose_mouse_click2(mouse_pos, choose));
}
