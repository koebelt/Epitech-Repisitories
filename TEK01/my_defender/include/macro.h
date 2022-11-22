/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** macro
*/

#ifndef MACRO_H_
#define MACRO_H_

#define BG "assets/menu/bg.png"
#define HDV "assets/buildings/hdv_sheets.png"
#define HDV_HEALTH 2000
#define ARCHERS "assets/buildings/archers_sheets.png"
#define ARCHERS_DAMAGE 20
#define ARCHERS_HEALTH 500
#define ARCHERS_COOLDOWN 1
#define ARCHERS_RANGE 300
#define TESLA "assets/buildings/tesla_sheets.png"
#define TESLA_DAMAGE 55
#define TESLA_HEALTH 1000
#define TESLA_COOLDOWN 0.5
#define TESLA_RANGE 150
#define WIZARD "assets/buildings/wizard_tower_sheets.png"
#define WIZARD_DAMAGE 95
#define WIZARD_HEALTH 1500
#define WIZARD_COOLDOWN 4
#define WIZARD_RANGE 200
#define INFERNO "assets/buildings/inferno_sheets.png"
#define INFERNO_DAMAGE 120
#define INFERNO_HEALTH 2000
#define INFERNO_COOLDOWN 5
#define INFERNO_RANGE 200
#define EAGLES "assets/buildings/eagles_sheets.png"
#define EAGLES_DAMAGE 200
#define EAGLES_HEALTH 2000
#define EAGLES_COOLDOWN 8
#define EAGLES_RANGE 500

#define MAP_1 "assets/maps/Map_Clashy_Constructs.png"
#define MAP_2 "assets/maps/Map_Classic.png"
#define MAP_5 "assets/maps/Map_PirateScenery.png"

#define SKELETON_WALK "assets/mobs/skeleton/skeleton_walk.png"
#define SKELETON_ATTACK "assets/mobs/skeleton/skeleton_attack.png"
#define SKELETON_DAMAGE 20
#define SKELETON_HEALTH 250
#define MINOTAUR_WALK "assets/mobs/minotaur/minotaur_walk.png"
#define MINOTAUR_ATTACK "assets/mobs/minotaur/minotaur_attack.png"
#define MINOTAUR_DAMAGE 400
#define MINOTAUR_HEALTH 700
#define GOLEM_WALK "assets/mobs/golem/golem_walk.png"
#define GOLEM_ATTACK "assets/mobs/golem/golem_attack.png"
#define GOLEM_DAMAGE 100
#define GOLEM_HEALTH 1000
#define GOBLIN_WALK "assets/mobs/goblin/goblin_walk.png"
#define GOBLIN_ATTACK "assets/mobs/goblin/goblin_attack.png"
#define GOBLIN_DAMAGE 15
#define GOBLIN_HEALTH 250
#define CYCLOP_WALK "assets/mobs/cyclop/cyclop_walk.png"
#define CYCLOP_ATTACK "assets/mobs/cyclop/cyclop_attack.png"
#define CYCLOP_DAMAGE 50
#define CYCLOP_HEALTH 600
#define ELEMENTAL_FLY "assets/mobs/elemental/elemental_fly.png"
#define ELEMENTAL_ATTACK "assets/mobs/elemental/elemental_attack.png"
#define ELEMENTAL_DAMAGE 200
#define ELEMENTAL_HEALTH 450

#define ENERGY_COOLDOWN 3

#define ALLY_POS_TOWER_1_X 500
#define ALLY_POS_TOWER_1_Y 350
#define ALLY_POS_TOWER_2_X 500
#define ALLY_POS_TOWER_2_Y 550
#define ALLY_POS_HDV_X 350
#define ALLY_POS_HDV_Y 490

#define ENEMY_POS_TOWER_1_X 1370
#define ENEMY_POS_TOWER_1_Y 350
#define ENEMY_POS_TOWER_2_X 1370
#define ENEMY_POS_TOWER_2_Y 550
#define ENEMY_POS_HDV_X 1520
#define ENEMY_POS_HDV_Y 490

#define SHOP_M "assets/menu/shop_menu.png"
#define ARCHER_T_BT "assets/menu/shop_bt/archer_tower_shop.png"
#define EAGLE_T_BT "assets/menu/shop_bt/eagle_tower_shop.png"
#define HDV_BT "assets/menu/shop_bt/hdv_button_shop.png"
#define INFERNO_T_BT "assets/menu/shop_bt/inferno_shop.png"
#define TESLA_T_BT "assets/menu/shop_bt/tesla_tower_shop.png"
#define WIZARD_T_BT "assets/menu/shop_bt/wizard_tower_shop.png"

#define ARROW_PROJ (sprite_info_t){0, 0, 0.2, 0.2, 0, 0, 100, 100, \
"assets/projectiles/arrow_projectile.png"}
#define WIZARD_PROJ (sprite_info_t){0, 0, 1, 1, 35, 80, 40, 40, \
"assets/projectiles/wizard_projectiles.png"}
#define INFERNO_PROJ (sprite_info_t){0, 0, 0.5, 0.5, 0, 306, 153, 153, \
"assets/projectiles/inferno_projectiles.png"}
#define EAGLE_PROJ (sprite_info_t){0, 0, 1, 1, 0, 65, 65, 75, \
"assets/projectiles/eagle_projectiles.png"}
#define TESLA_PROJ (sprite_info_t){0, 0, 1, 1, 0, 120, 60, 60, \
"assets/projectiles/tesla_projectiles.png"}

#define BLUE_HEALTH (sprite_info_t){0, 0, 0.2, 0.2, 0, 0, 34, 327, \
"assets/game_ui/bar_2.png"}
#define RED_HEALTH (sprite_info_t){0, 0, 0.2, 0.2, 0, 0, 34, 327, \
"assets/game_ui/bar_4.png"}

#endif /* !MACRO_H_ */