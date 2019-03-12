/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** event mouse/keyboard for menu scene
*/

#include "my_rpg.h"

void	drag_armor_to_inv(core_t *cor, int id, V2I pos_mouse, V2F pos_case)
{
	int save_case = 0;

	if (verif_is_on_inventory_cases(pos_mouse) == 1) {
		save_case = recup_select_armor_id(cor);
		SPR_SETPOS(cor->obj_inv.select, pos_case);
		cor->armor[save_case].id = cor->inv[recup_select_item_id(cor)];
		cor->inv[recup_actual_item_id(cor)] = id;
		cor->obj_inv.which_select = 0;
	}
}

void	drag_armor_to_armor(core_t *cor, int id, V2F pos_case)
{
	int save = 0;
	int id_2 = 0;

	if (verif_is_on_armor_cases(cor, &pos_case) == 1 &&
	verif_is_good_armor_type(cor, id) == 1) {
		save = recup_select_armor_id(cor);
		SPR_SETPOS(cor->obj_inv.select_big, pos_case);
		id_2 = cor->armor[recup_select_armor_id(cor)].id;
		cor->armor[save].id = id_2;
		cor->armor[recup_select_armor_id(cor)].id = id;
		cor->obj_inv.which_select = 1;
	}
}

void	set_select_armor_2(core_t *cor, V2I pos_mouse, V2F pos_case,
	int *state)
{
	if (cor->obj_inv.is_drag > 3 &&
	cor->obj_inv.which_select == 1 && *state == 0) {
		drag_armor_to_armor(cor,
		cor->armor[recup_select_armor_id(cor)].id, pos_case);
		drag_armor_to_inv(cor,
		cor->armor[recup_select_armor_id(cor)].id, pos_mouse, pos_case);
		cor->obj_inv.is_drag = 0;
		*state = 1;
	}
	if (cor->obj_inv.which_select == 1 && *state == 0)
		cor->obj_inv.is_drag = 0;
}


void	set_select_armor(core_t *cor, V2I pos_mouse, V2F pos_case)
{
	int id = cor->armor[recup_select_armor_id(cor)].id;
	int state = 0;

	if (sfMouse_isButtonPressed(sfMouseLeft) && cor->obj_inv.is_drag > 3 &&
	id != 0 && cor->obj_inv.which_select == 1) {
		set_item_draged(cor, id);
		state = 1;
	}
	if (sfMouse_isButtonPressed(sfMouseLeft) &&
	verif_is_on_armor_cases(cor, &pos_case) == 1 &&
	cor->obj_inv.is_drag <= 3 && state == 0) {
		cor->obj_inv.is_drag++;
		SPR_SETPOS(cor->obj_inv.select_big, pos_case);
		cor->obj_inv.which_select = 1;
		state = 1;
	}
	set_select_armor_2(cor, pos_mouse, pos_case, &state);
}

void	display_obj_armor(core_t *cor, V2I pos_mouse, V2F pos_case)
{
	set_select_armor(cor, pos_mouse, pos_case);
	if (verif_is_on_armor_cases(cor, &pos_case) == 1) {
		RCT_SETSIZ(cor->obj_inv.actual, (V2F){128, 128});
		RCT_SETPOS(cor->obj_inv.actual, pos_case);
		RDW_DRWRCT(cor->window, cor->obj_inv.actual, NULL);
	}
}
