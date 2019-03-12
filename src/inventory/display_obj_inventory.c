/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** event mouse/keyboard for menu scene
*/

#include "my_rpg.h"

void	drag_inv_to_inv(core_t *cor, int id, V2I pos_mouse, V2F pos_case)
{
	int save_case = 0;

	if (verif_is_on_inventory_cases(pos_mouse) == 1) {
		save_case = recup_select_item_id(cor);
		SPR_SETPOS(cor->obj_inv.select, pos_case);
		cor->inv[save_case] = cor->inv[recup_select_item_id(cor)];
		cor->inv[recup_select_item_id(cor)] = id;
		cor->obj_inv.which_select = 0;
	}
}

void	drag_inv_to_armor(core_t *cor, int id, V2F pos_case)
{
	int save = 0;

	if (verif_is_on_armor_cases(cor, &pos_case) == 1 &&
	verif_is_good_armor_type(cor, id) == 1) {
		save = recup_select_item_id(cor);
		SPR_SETPOS(cor->obj_inv.select_big, pos_case);
		cor->inv[save] = cor->armor[recup_select_armor_id(cor)].id;
		cor->armor[recup_actual_armor_id(cor)].id = id;
		cor->obj_inv.which_select = 1;
	}
}

void	set_select_inventory_2(core_t *cor, V2F pos_case, V2I pos_mouse,
int *state)
{
	if (cor->obj_inv.is_drag > 3 &&
	cor->obj_inv.which_select == 0 && *state == 0) {
		drag_inv_to_inv(cor, cor->inv[recup_select_item_id(cor)],
		pos_mouse, pos_case);
		drag_inv_to_armor(cor, cor->inv[recup_select_item_id(cor)],
		pos_case);
		cor->obj_inv.is_drag = 0;
		*state = 1;
	}
	if (cor->obj_inv.which_select == 0 && *state == 0)
		cor->obj_inv.is_drag = 0;
}

void	set_select_inventory(core_t *cor, V2F pos_case, V2I pos_mouse)
{
	int id = cor->inv[recup_select_item_id(cor)];
	int state = 0;

	if (sfMouse_isButtonPressed(sfMouseLeft) && cor->obj_inv.is_drag > 3 &&
	id != 0 && cor->obj_inv.which_select == 0) {
		set_item_draged(cor, id);
		state = 1;
	}
	if (sfMouse_isButtonPressed(sfMouseLeft) &&
	verif_is_on_inventory_cases(pos_mouse) == 1 &&
	cor->obj_inv.is_drag <= 3 && state == 0) {
		cor->obj_inv.is_drag++;
		SPR_SETPOS(cor->obj_inv.select, pos_case);
		cor->obj_inv.which_select = 0;
		state = 1;
	}
	set_select_inventory_2(cor, pos_case, pos_mouse, &state);
}

void	display_obj_inventory(core_t *cor, V2I pos_mouse, V2F pos_case)
{
	set_select_inventory(cor, pos_case, pos_mouse);
	if (verif_is_on_inventory_cases(pos_mouse) == 1) {
		RCT_SETSIZ(cor->obj_inv.actual, (V2F){64, 64});
		RCT_SETPOS(cor->obj_inv.actual, pos_case);
		RDW_DRWRCT(cor->window, cor->obj_inv.actual, NULL);
	}
}
