/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** event mouse/keyboard for menu scene
*/

#include "my_rpg.h"

void	unequip_item(core_t *cor)
{
	int id = 0;

	for (int i = 0; i < NB_INVENTORY_CASE; i++) {
		if (cor->inv[i] == 0) {
			id = cor->armor[recup_select_armor_id(cor)].id;
			cor->inv[i] = id;
			cor->armor[recup_select_armor_id(cor)].id = 0;
		}
	}
}

void	equip_item(core_t *cor)
{
	item_t item = cor->item[cor->inv[recup_select_item_id(cor)]];
	int tmp = 0;

	for (int i = 0; i < NB_ARMOR_CASE; i++) {
		if (cor->armor[i].type == item.type && ((item.type == DICE &&
		cor->armor[i].id == 0) || item.type != DICE)) {
			tmp = cor->armor[i].id;
			cor->armor[i].id = cor->inv[recup_select_item_id(cor)];
			cor->inv[recup_select_item_id(cor)] = tmp;
		}
	}
}

void	switch_select_item_armor(core_t *cor)
{
	if (cor->obj_inv.which_select == 0) {
		SPR_SETPOS(cor->obj_inv.select_big, cor->armor[0].armor_pos);
		cor->obj_inv.which_select = 1;
	} else {
		SPR_SETPOS(cor->obj_inv.select, (V2F){794, 190});
		cor->obj_inv.which_select = 0;
	}
}

void	event_inventory(core_t *cor, int *status)
{
	if (macro_button_click(sfKeyReturn, status)) {
		if (cor->obj_inv.which_select == 0 &&
		cor->inv[recup_select_item_id(cor)] != 0)
			equip_item(cor);
		if (cor->obj_inv.which_select == 1 &&
		cor->armor[recup_select_armor_id(cor)].id != 0)
			unequip_item(cor);
	}
	if (macro_button_click(sfKeyTab, status))
		switch_select_item_armor(cor);
	if (macro_button_click(sfKeyJ, status) &&
	cor->item[cor->inv[recup_select_item_id(cor)]].type != QUEST)
		cor->inv[recup_select_item_id(cor)] = 0;
}
