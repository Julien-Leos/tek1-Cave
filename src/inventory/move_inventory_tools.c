/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** event mouse/keyboard for menu scene
*/

#include "my_rpg.h"

void	move_select_item(core_t *cor, int off_x, int off_y, int *status)
{
	V2F pos = SPR_GETPOS(cor->obj_inv.select);
	V2F new_pos = {pos.x + off_x, pos.y + off_y};

	if (794 <= new_pos.x && new_pos.x <= 1818 &&
	190 <= new_pos.y && new_pos.y <= 638) {
		*status = 1;
		sfSound_play(cor->sound[1].obj);
		SPR_SETPOS(cor->obj_inv.select, new_pos);
	}
}

void	move_select_armor(core_t *cor, int off, int *status)
{
	int id = recup_select_armor_id(cor) + off;

	if (id >= 0 && id <= 9) {
		*status = 1;
		sfSound_play(cor->sound[1].obj);
		SPR_SETPOS(cor->obj_inv.select_big, cor->armor[id].armor_pos);
	}
}
