/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** event mouse/keyboard for menu scene
*/

#include "my_rpg.h"

void	actualise_player_stat(core_t *cor)
{
	int id = 0;

	for (int e = 0; e < 6; e++) {
		cor->ply.chrc[e] = 0;
		for (int i = 4; i < 10; i++) {
			id = cor->item[cor->armor[i].id].chrc[e];
			cor->ply.chrc[e] += id < 0 ? 0 : id;
		}
	}
	for (int e = 6; e < 12; e++) {
		cor->ply.chrc[e] = 0;
		for (int i = 0; i < 4; i++) {
			id = cor->item[cor->armor[i].id].chrc[e];
			cor->ply.chrc[e] += id < 0 ? 0 : id;
		}
	}
}

void	display_life_and_armor(core_t *cor)
{
	TXT_SETSTR(cor->obj_inv.txt, my_strcat("PV: ",
	my_itoa(cor->ply.life)));
	TXT_SETPOS(cor->obj_inv.txt, (V2F){1000, 745});
	RDW_DRWTXT(cor->window, cor->obj_inv.txt, NULL);
	TXT_SETSTR(cor->obj_inv.txt, my_strcat("ARM: ",
	my_itoa(cor->ply.chrc[6])));
	TXT_SETPOS(cor->obj_inv.txt, (V2F){1490, 745});
	RDW_DRWTXT(cor->window, cor->obj_inv.txt, NULL);
}

void	display_player_characteristic(core_t *cor)
{
	V2F pos = {1000, 815};
	char *chrc = NULL;
	int value = 0;

	for (int i = 7, e = 1; i < 12; i++, e++) {
		value = my_percent(cor->ply.chrc[i] * MULT, PERCENT);
		chrc = my_itoa(value);
		chrc = my_strcat(" > +", my_strcat(chrc, "%"));
		chrc = my_strcat(my_itoa(cor->ply.chrc[i]), chrc);
		chrc = my_strcat(cor->chrc_name[i], chrc);
		TXT_SETSTR(cor->obj_inv.txt, chrc);
		TXT_SETPOS(cor->obj_inv.txt, pos);
		RDW_DRWTXT(cor->window, cor->obj_inv.txt, NULL);
		pos.y += 50;
		if (e % 3 == 0 && e != 0) {
			pos.x += 490;
			pos.y = 815;
		}
	}
}

void 	display_level(core_t *cor)
{
	char *ch = NULL;
	V2F pos = (V2F){790, 700};
	int len = 0;

	ch = my_itoa(cor->ply.level);
	len = my_strlen(ch);
	TXT_SETSTR(cor->obj_inv.txt, "NIVEAU");
	TXT_SETPOS(cor->obj_inv.txt, pos);
	RDW_DRWTXT(cor->window, cor->obj_inv.txt, NULL);
	pos.x += 182 - len * 21;
	TXT_SETSTR(cor->obj_inv.txt, ch);
	TXT_SETPOS(cor->obj_inv.txt, pos);
	RDW_DRWTXT(cor->window, cor->obj_inv.txt, NULL);
}

void	display_static(core_t *cor)
{
	V2F save_pos = SPR_GETPOS(cor->ply.spt);

	SPR_SETPOS(cor->obj[14]->spr, (V2F){780, 737});
	SPR_SETSCL(cor->obj[14]->spr, (V2F){3, 3});
	sfSprite_setTextureRect(cor->obj[14]->spr, (IRC){512, 0, 64, 64});
	RDW_DRWSPR(cor->window, cor->obj[14]->spr, NULL);
	display_life_and_armor(cor);
	display_player_characteristic(cor);
	SPR_SETPOS(cor->ply.spt, save_pos);
	SPR_SETSCL(cor->ply.spt, (V2F){1, 1});
	display_level(cor);
}
