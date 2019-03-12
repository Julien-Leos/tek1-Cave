/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** event mouse/keyboard for menu scene
*/

#include "my_rpg.h"

void	display_item_sprite(core_t *cor, int id)
{
	SPR_SETSCL(cor->item[id].spt, (V2F){8, 8});
	SPR_SETPOS(cor->item[id].spt, (V2F){813, 782});
	RDW_DRWSPR(cor->window, cor->item[id].spt, NULL);
}

void	display_item_name(core_t *cor, int id)
{
	TXT_SETSIZ(cor->obj_inv.txt, 40);
	TXT_SETSTR(cor->obj_inv.txt, cor->item[id].name);
	TXT_SETPOS(cor->obj_inv.txt, (V2F){1000, 740});
	RDW_DRWTXT(cor->window, cor->obj_inv.txt, NULL);
}

void	display_item_description(core_t *cor, int id)
{
	TXT_SETSIZ(cor->obj_inv.txt, 32);
	TXT_SETSTR(cor->obj_inv.txt, cor->item[id].des);
	TXT_SETPOS(cor->obj_inv.txt, (V2F){1000, 815});
	RDW_DRWTXT(cor->window, cor->obj_inv.txt, NULL);
}

void	display_item_characteristic(core_t *cor, int id)
{
	V2F pos = {1460, 815};
	char *ch = NULL;
	char *num = NULL;

	for (int i = 0, e = 0; i < 13; i++) {
		if (cor->item[id].chrc[i] == -1)
			continue;
		num = my_itoa(cor->item[id].chrc[i]);
		ch = my_strcat(cor->chrc_name[i], num);
		ch = (cor->item[id].type == ITEM) ? my_strcat(ch, " %") : ch;
		TXT_SETSTR(cor->obj_inv.txt, ch);
		TXT_SETPOS(cor->obj_inv.txt, pos);
		RDW_DRWTXT(cor->window, cor->obj_inv.txt, NULL);
		pos.y += 50;
		e++;
		if (e % 3 == 0 && e != 0) {
			pos.x += 200;
			pos.y = 815;
		}
	}
}

void	display_infobar(core_t *cor)
{
	int id = 0;

	if (cor->obj_inv.which_select == 0 &&
	cor->inv[recup_select_item_id(cor)] != 0)
		id = cor->inv[recup_select_item_id(cor)];
	else if (cor->obj_inv.which_select == 1 &&
	cor->armor[recup_select_armor_id(cor)].id != 0)
		id = cor->armor[recup_select_armor_id(cor)].id;
	if ((cor->obj_inv.which_select == 0 && id != 0) ||
	(cor->obj_inv.which_select == 1 && id != 0)) {
		display_item_sprite(cor, id);
		display_item_name(cor, id);
		display_item_description(cor, id);
		display_item_characteristic(cor, id);
	}
}
