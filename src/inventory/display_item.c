/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** event mouse/keyboard for menu scene
*/

#include "my_rpg.h"

void	display_item_inventory(core_t *cor)
{
	V2F pos = {797, 193};
	int inv_id = 0;

	for (int id = 0; id < NB_INVENTORY_CASE; pos.x += 68, id++) {
		inv_id = cor->inv[id];
		if (id % 16 == 0 && id != 0) {
			pos.y += 70;
			pos.x = 797;
		}
		if (inv_id != 0) {
			SPR_SETSCL(cor->item[inv_id].spt, (V2F){4, 4});
			SPR_SETPOS(cor->item[inv_id].spt, pos);
			RDW_DRWSPR(cor->window, cor->item[inv_id].spt, NULL);
		}
	}
}

void	display_item_armor(core_t *cor)
{
	int arm_id = 0;
	V2F arm_pos;

	for (int id = 0; id < NB_ARMOR_CASE; id++) {
		arm_id = cor->armor[id].id;
		arm_pos = cor->armor[id].armor_pos;
		if (arm_id != 0) {
			SPR_SETSCL(cor->item[arm_id].spt, (V2F){8, 8});
			SPR_SETPOS(cor->item[arm_id].spt, arm_pos);
			RDW_DRWSPR(cor->window, cor->item[arm_id].spt, NULL);
		}
	}
}

void	display_item(core_t *cor)
{
	display_item_inventory(cor);
	display_item_armor(cor);
}
