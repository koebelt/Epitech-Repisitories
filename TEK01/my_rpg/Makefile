##
## EPITECH PROJECT, 2021
## B-MUL-200-STG-2-1-myrpg-matheo.vitali
## File description:
## Makefile
##

SRC 	=	src/main.c	\
			src/utilities/quest_utilities.c \
			src/utilities/interact_utilities.c \
			src/utilities/sprites_utilities.c	\
			src/utilities/button_utilities.c	\
			src/utilities/item_utilities.c \
			src/utilities/mouse_utilities.c \
			src/utilities/text_utilities.c \
			src/utilities/my_strcmp.c \
			src/utilities/my_strcat.c \
			src/utilities/int_to_str.c \
			src/utilities/music_utilities.c	\
			src/utilities/my_getnbr.c	\
			src/utilities/randomize.c	\
			src/utilities/mouse_hover_item.c \
			src/exterior/init_quest.c \
			src/exterior/npcs_with_quest.c \
			src/exterior/exterior_main.c	\
			src/exterior/map.c	\
			src/exterior/player.c	\
			src/exterior/dungeons_entrances.c	\
			src/exterior/animate_player_ext.c \
			src/menu/menu.c		\
			src/menu/event_menu.c \
			src/menu/settings.c	\
			src/inventory/inventory.c \
			src/inventory/equip.c \
			src/inventory/equip_items.c \
			src/inventory/event_inventory.c \
			src/inventory/init_inventory.c \
			src/inventory/set_inv_first.c \
			src/inventory/set_inv_second_and_draw.c \
			src/inventory/get_level_and_stats.c \
			src/inventory/create_tab.c \
			src/items/items.c \
			src/items/destroy_items.c \
			src/items/randomise_drop.c \
			src/items/replace_items.c \
			src/dongeon/generate_dongeon.c	\
			src/dongeon/run_dongeon.c	\
			src/dongeon/player.c	\
			src/dongeon/monsters.c	\
			src/dongeon/projectile.c	\
			src/dongeon/arrow.c	\
			src/dongeon/dongeon_misc.c	\
			src/dongeon/move_arrow.c \
			src/dongeon/add_doors.c \
			src/dongeon/init_rooms.c \
			src/dongeon/display_monsters.c \
			src/dongeon/summon_monster.c \
			src/dongeon/monster_attack.c \
			src/dongeon/animate_monster.c \
			src/dongeon/delete_monster_create_body.c \
			src/dongeon/move_monster.c \
			src/dongeon/animate_player_dong.c \
			src/dongeon/player_and_door_collision.c \
			src/dongeon/player_wall_collision.c \
			src/dongeon/create_and_destroy_spell.c \
			src/dongeon/move_spell.c \
			src/dongeon/init_dungeon.c \
			src/dongeon/run_dungeon_second.c \
			src/menu/event_videostg.c \
			src/pause/pause.c \
			src/menu/bar.c \
			src/menu/how_to_play.c


NAME	=	my_rpg

OBJ	=	$(SRC:.c=.o)

CFLAGS = 	-lcsfml-graphics	\
			-lcsfml-window	\
			-lcsfml-system	\
			-lcsfml-audio	\
			-lm				\
			-Wall			\
			-Werror			\
			-Wextra			\
			-g				\

all:	$(OBJ)
	gcc -o $(NAME) ${OBJ} ${CFLAGS}
	make clean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re