/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

void	init_new_battle_sub(core_t *cor)
{
	for (int i = 0; i < 6; i++) {
		cor->btl.total_elem[i] = 0;
		cor->obj_btl.last_dice[i] = -1;
		cor->obj_btl.dice_cycle[i] = 0;
	}
	for (int i = 0; i < 5; i++)
		cor->btl.special[i] = 0;
	sfSprite_setColor(cor->obj[cor->btl.enn_id + 35]->spr, sfWhite);
	SPR_SETPOS(cor->obj[17]->spr, (V2F){800, 790});
}

void	init_new_battle(core_t *cor, int mob)
{
	cor->btl.mob_id = mob;
	cor->btl.turn_state = -2;
	cor->btl.life[0] = cor->ply.life;
	cor->btl.life[1] = cor->mob[mob].life;
	cor->btl.dmg[0] = -1;
	cor->btl.dmg[1] = -1;
	cor->btl.dmg_cycle[0] = 0;
	cor->btl.dmg_cycle[1] = 0;
	cor->btl.msg_cycle = 0;
	cor->btl.state.anim_main = 0;
	cor->btl.state.anim_ennemy = 0;
	cor->btl.state.is_dead = 0;
	cor->button[18].state = 1;
	cor->button[19].state = 0;
	cor->button[20].state = 0;
	init_new_battle_sub(cor);
}
