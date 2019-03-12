/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

void	verif_life(int *life, int max_life)
{
	if (*life > max_life)
		*life = max_life;
	if (*life < 0)
		*life = 0;
}

float	recup_life(int life, int life_max)
{
	float res = (float)life / (float)life_max * 350;

	return (res);
}

void	display_battle_life(core_t *cor)
{
	int life_ply_max = cor->ply.life;
	int life_mob_max = cor->mob[cor->btl.mob_id].life;
	float life_ply = 0;
	float life_mob = 0;

	verif_life(&cor->btl.life[0], cor->ply.life);
	verif_life(&cor->btl.life[1], cor->mob[cor->btl.mob_id].life);
	life_ply = recup_life(cor->btl.life[0], life_ply_max);
	life_mob = recup_life(cor->btl.life[1], life_mob_max);
	RDW_DRWSPR(cor->window, cor->obj[23]->spr, NULL);
	RCT_SETSIZ(cor->obj_btl.life, (V2F){life_ply, 50});
	RCT_SETPOS(cor->obj_btl.life, (V2F){190, 150});
	RCT_SETPOS(cor->obj_btl.out_life, (V2F){190, 150});
	RDW_DRWRCT(cor->window, cor->obj_btl.life, NULL);
	RDW_DRWRCT(cor->window, cor->obj_btl.out_life, NULL);
	RCT_SETSIZ(cor->obj_btl.life, (V2F){life_mob, 50});
	RCT_SETPOS(cor->obj_btl.life, (V2F){1320, 150});
	RCT_SETPOS(cor->obj_btl.out_life, (V2F){1320, 150});
	RDW_DRWRCT(cor->window, cor->obj_btl.life, NULL);
	RDW_DRWRCT(cor->window, cor->obj_btl.out_life, NULL);
}
