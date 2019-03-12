/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

IRC	recup_rect_dice(int face)
{
	IRC pos = {face * 50, 0, 50, 50};

	return (pos);
}

void	set_rect(core_t *cor, int i)
{
	int cycle = cor->obj_btl.dice_cycle[i];
	int last_dice = cor->obj_btl.last_dice[i];

	if ((cycle % (cycle / 10 + 1) == 0 || cycle == 50) && cycle <= 50)
		SPR_STXTRE(cor->obj_btl.dice[i], recup_rect_dice(last_dice));
}

void	display_battle_dice_face(core_t *cor)
{
	V2F pos = {235, 40};

	for (int i = 0; i < 6; i++, pos.x += 250) {
		if (cor->obj_btl.last_dice[i] != -1 &&
		cor->armor[i + 4].id != 0) {
			SPR_SETPOS(cor->obj_btl.dice[i], pos);
			set_rect(cor, i);
			RDW_DRWSPR(cor->window, cor->obj_btl.dice[i], NULL);
		}
		if (cor->obj_btl.dice_cycle[i] == 85) {
			cor->obj_btl.dice_cycle[i] = 0;
			cor->btl.turn_state = 0;
		} else
			cor->obj_btl.dice_cycle[i]++;
	}
}
