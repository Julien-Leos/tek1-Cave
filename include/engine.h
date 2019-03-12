/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** engine header with prototypes and struct
*/

#ifndef __ENGINE_H__
#define __ENGINE_H__

typedef struct state_s {
	int 	in_menu;
	int 	in_submenu;
	int 	in_quest;
	int	is_dead;
	int 	anim_main;
	int 	anim_spell;
	int 	anim_ennemy;
	int 	change_scene;
	int 	nb_ennemy;
} state_t;

typedef struct obj_inv_s {
	sfText *txt;
	sfSprite *background;
	sfSprite *select;
	sfSprite *select_big;
	sfRectangleShape *actual;
	int which_select;
	int is_drag;
	int pannel;
} obj_inv_t;

typedef struct btl_s {
	int total_elem[6];
	int life[2];
	int dmg[2];
	int dmg_cycle[2];
	int msg_cycle;
	int turn_state;
	int enn_id;
	int mob_id;
	int special[5];
	struct state_s state;
} btl_t;

typedef struct obj_btl_s {
	sfSprite *dice[6];
	int last_dice[6];
	int dice_cycle[6];
	sfRectangleShape *life;
	sfRectangleShape *out_life;
	sfRectangleShape *actual;
	sfText *txt;
	char *dmg_txt[2];
	sfColor color_txt[2];
	int which_menu;
} obj_btl_t;

typedef struct obj_spell_s {
	sfText *txt;
	sfRectangleShape *actual;
	int nbr_spell;
} obj_spell_t;

#endif
