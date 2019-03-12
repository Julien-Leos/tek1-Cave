/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** event mouse/keyboard for menu scene
*/

#include "my_rpg.h"

int	verif_is_on_armor_cases(core_t *cor, V2F *pos_case)
{
	for (int i = 0; i < NB_ARMOR_CASE; i++) {
		*pos_case = cor->armor[i].armor_pos;
		if (cor->pos_mouse.x >= pos_case->x &&
		cor->pos_mouse.x <= pos_case->x + 128 &&
		cor->pos_mouse.y >= pos_case->y &&
		cor->pos_mouse.y <= pos_case->y + 128)
			return (1);
	}
	return (0);
}

int	verif_is_good_armor_type(core_t *cor, int id)
{
	if (cor->armor[recup_actual_armor_id(cor)].type == cor->item[id].type)
		return (1);
	return (0);
}

int	verif_is_on_inventory_cases(V2I pos_mouse)
{
	if (10 < pos_mouse.x && pos_mouse.x < 27 &&
	2 < pos_mouse.y && pos_mouse.y < 10)
		return (1);
	return (0);
}

void	set_item_draged(core_t *cor, int id)
{
	V2F pos_mouse = {cor->pos_mouse.x, cor->pos_mouse.y};

	SPR_SETSCL(cor->item[id].spt, (V2F){4, 4});
	SPR_SETPOS(cor->item[id].spt, pos_mouse);
	RDW_DRWSPR(cor->window, cor->item[id].spt, NULL);
}

void	display_obj(core_t *cor)
{
	int pos_mouse_x = (cor->pos_mouse.x - 46) / 68;
	int pos_mouse_y = (cor->pos_mouse.y + 20) / 70;
	V2I pos_mouse = {pos_mouse_x, pos_mouse_y};
	V2F pos_case = {pos_mouse.x * 68 + 46, pos_mouse.y * 70 - 20};

	RDW_DRWSPR(cor->window, cor->obj_inv.background, NULL);
	display_obj_inventory(cor, pos_mouse, pos_case);
	display_obj_armor(cor, pos_mouse, pos_case);
	if (cor->obj_inv.which_select == 0)
		RDW_DRWSPR(cor->window, cor->obj_inv.select, NULL);
	else
		RDW_DRWSPR(cor->window, cor->obj_inv.select_big, NULL);
}
