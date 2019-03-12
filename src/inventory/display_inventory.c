/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** event mouse/keyboard for menu scene
*/

#include "my_rpg.h"

int	recup_select_item_id(core_t *cor)
{
	V2F pos1 = SPR_GETPOS(cor->obj_inv.select);
	V2I pos2 = {(pos1.x - 794) / 68, (pos1.y - 190) / 70};

	return (pos2.y * 16 + pos2.x);
}

int	recup_actual_item_id(core_t *cor)
{
	V2F pos1 = RCT_GETPOS(cor->obj_inv.actual);
	V2I pos2 = {(pos1.x - 794) / 68, (pos1.y - 190) / 70};

	return (pos2.y * 16 + pos2.x);
}

int	recup_select_armor_id(core_t *cor)
{
	V2F select_pos = SPR_GETPOS(cor->obj_inv.select_big);

	for (int i = 0; i < NB_ARMOR_CASE; i++) {
		if (cor->armor[i].armor_pos.x == select_pos.x &&
		cor->armor[i].armor_pos.y == select_pos.y)
			return (i);
	}
	return (0);
}

int	recup_actual_armor_id(core_t *cor)
{
	V2F select_pos = RCT_GETPOS(cor->obj_inv.actual);

	for (int i = 0; i < NB_ARMOR_CASE; i++) {
		if (cor->armor[i].armor_pos.x == select_pos.x &&
		cor->armor[i].armor_pos.y == select_pos.y)
			return (i);
	}
	return (0);
}

void	display_inventory(core_t *cor)
{
	display_obj(cor);
	display_item(cor);
	if (cor->obj_inv.pannel == 1)
		display_static(cor);
	else
		display_infobar(cor);
	actualise_player_stat(cor);
}
