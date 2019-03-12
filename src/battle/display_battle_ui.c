/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

void	display_battle_background(core_t *cor)
{
	RDW_DRWSPR(cor->window, cor->obj[19]->spr, NULL);
	RDW_DRWSPR(cor->window, cor->obj[20]->spr, NULL);
	RDW_DRWSPR(cor->window, cor->obj[21]->spr, NULL);
}

void	display_battle_nbr_elements(core_t *cor)
{
	V2F pos = {500, 785};

	for (int i = 0; i < 6; i++, pos.y += 107) {
		if (i % 3 == 0 && i != 0) {
			pos.x += 200;
			pos.y = 785;
		}
		TXT_SETSIZ(cor->obj_btl.txt, 55);
		TXT_SETCLR(cor->obj_btl.txt, CLR_FRRGBA(230, 230, 230, 255));
		TXT_SETPOS(cor->obj_btl.txt, pos);
		TXT_SETSTR(cor->obj_btl.txt, my_itoa(cor->btl.total_elem[i]));
		RDW_DRWTXT(cor->window, cor->obj_btl.txt, NULL);
	}
}

void 	display_battle_characters(core_t *cor)
{
	int 	id = cor->btl.enn_id;

	if (sfKeyboard_isKeyPressed(sfKeyQ))
		cor->btl.state.anim_main = 6;
	SPR_SETPOS(cor->obj[14]->spr, (V2F){200, 500});
	SPR_SETSCL(cor->obj[14]->spr, (V2F){3, 3});
	animation_stand_main_character(cor);
	animation_hit_main_character(cor);
	animation_acast_main_character(cor);
	animation_bcast_main_character(cor);
	animation_dodge_main_character(cor);
	animation_dead_main_character(cor);
	animation_win_main_character(cor);
	animation_cast_ennemy(cor, id);
	animation_hit_ennemy(cor, id);
	animation_dead_ennemy(cor, id);
	RDW_DRWSPR(cor->window, cor->obj[14]->spr, NULL);
	RDW_DRWSPR(cor->window, cor->obj[id + 35]->spr, NULL);
}
