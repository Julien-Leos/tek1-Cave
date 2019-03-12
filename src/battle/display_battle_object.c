/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

void	display_battle_object_spr(core_t *cor)
{
	V2F pos = {0, 854};
	int id[4] = {1, 2, 60, 61};
	char *str = NULL;

	for (int i = 0; i < 4; i++) {
		pos.x = 1056 + i * 128;
		str = my_itoa(recup_nbr_item(cor, id[i]));
		SPR_SETSCL(cor->item[id[i]].spt, (V2F){8, 8});
		SPR_SETPOS(cor->item[id[i]].spt, pos);
		RDW_DRWSPR(cor->window, cor->item[id[i]].spt, NULL);
		TXT_SETPOS(cor->obj_btl.txt, (V2F){pos.x + 10, pos.y + 10});
		TXT_SETSTR(cor->obj_btl.txt, str);
		RDW_DRWTXT(cor->window, cor->obj_btl.txt, NULL);
	}
}

void	set_battle_object_select(core_t *cor, V2F pos_case)
{
	if (sfMouse_isButtonPressed(sfMouseLeft)) {
		SPR_SETPOS(cor->obj[17]->spr, pos_case);
		select_conso(cor);
	}
}

void	display_battle_object_select(core_t *cor, V2I pos_mouse, V2F pos_case)
{
	if (7 < pos_mouse.x && pos_mouse.x < 12 &&
	5 < pos_mouse.y && pos_mouse.y < 7) {
		set_battle_object_select(cor, pos_case);
		RCT_SETSIZ(cor->obj_btl.actual, (V2F){128, 128});
		RCT_SETPOS(cor->obj_btl.actual, pos_case);
		RDW_DRWRCT(cor->window, cor->obj_btl.actual, NULL);
	}
	SPR_SETSCL(cor->obj[17]->spr, (V2F){0.5, 0.5});
	RDW_DRWSPR(cor->window, cor->obj[17]->spr, NULL);
}

void	display_battle_object(core_t *cor)
{
	int pos_mouse_x = (cor->pos_mouse.x - 32) / 128;
	int pos_mouse_y = (cor->pos_mouse.y - 86) / 128;
	V2I pos_mouse = {pos_mouse_x, pos_mouse_y};
	V2F pos_case = {pos_mouse.x * 128 + 32, pos_mouse.y * 128 + 86};

	if (cor->obj_btl.which_menu == 0)
		SPR_SETPOS(cor->obj[17]->spr, (V2F){1056, 854});
	cor->obj_btl.which_menu = 1;
	display_battle_object_spr(cor);
	display_battle_object_select(cor, pos_mouse, pos_case);
}
