/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** event for battle scene
*/

#include "my_rpg.h"

void	display_spell_des_1(core_t *cor, int id)
{
	switch (id) {
		case 0:
			TXT_SETSTR(cor->obj_spell.txt, TXT_FIREBALL);
			break;
		case 1:
			TXT_SETSTR(cor->obj_spell.txt, TXT_BRAMBLE);
			break;
		case 2:
			TXT_SETSTR(cor->obj_spell.txt, TXT_WIND1);
			break;
		case 3:
			TXT_SETSTR(cor->obj_spell.txt, TXT_LIGHT);
			break;
	}
}

void	display_spell_des_2(core_t *cor, int id)
{
	switch (id) {
		case 4:
			TXT_SETSTR(cor->obj_spell.txt, TXT_FROG);
			break;
		case 5:
			TXT_SETSTR(cor->obj_spell.txt, TXT_HEAL);
			break;
		case 6:
			TXT_SETSTR(cor->obj_spell.txt, TXT_DARK);
			break;
		case 7:
			TXT_SETSTR(cor->obj_spell.txt, TXT_CRIT);
			break;
	}
}

void	display_spell_menu_star(core_t *cor)
{
	V2F pos = {0, 0};

	for (int i = 0; i < 4; i++) {
		if (cor->ply.spell[i] != -1) {
			pos.x = 287 + cor->ply.spell[i] % 4 * 256;
			pos.y = 268 + cor->ply.spell[i] / 4 * 256;
			SPR_SETSCL(cor->obj[34]->spr, (V2F){0.5, 0.5});
			SPR_SETPOS(cor->obj[34]->spr, pos);
			RDW_DRWSPR(cor->window, cor->obj[34]->spr, NULL);
		}
	}
}

void	display_spell_menu_spr(core_t *cor)
{
	V2F pos = {0, 0};

	for (int i = 0, x = 0, y = 0; i < 8; i++, x++) {
		if (x % 4 == 0 && x != 0) {
			x = 0;
			y++;
		}
		pos.x = 100 + x * 256;
		pos.y = 256 + y * 256;
		SPR_STXTRE(cor->obj[31]->spr, (IRC){i * 256, 0, 256, 256});
		SPR_SETPOS(cor->obj[31]->spr, pos);
		RDW_DRWSPR(cor->window, cor->obj[31]->spr, NULL);
	}
}

void 	display_spell_menu(core_t *cor)
{
	V2I pos1 = {(cor->pos_mouse.x - 100) / 256, (cor->pos_mouse.y) / 256};
	V2F pos2 = {pos1.x * 256 + 100, pos1.y * 256};
	V2F pos3 = SPR_GETPOS(cor->obj[17]->spr);

	RDW_DRWSPR(cor->window, cor->obj[13]->spr, NULL);
	display_spell_menu_spr(cor);
	if (0 <= pos1.x && pos1.x <= 3 && 1 <= pos1.y && pos1.y <= 2) {
		RCT_SETSIZ(cor->obj_spell.actual, (V2F){256, 256});
		RCT_SETPOS(cor->obj_spell.actual, pos2);
		RDW_DRWRCT(cor->window, cor->obj_spell.actual, NULL);
	}
	display_spell_menu_star(cor);
	display_spell_des_1(cor, id_spell_from_pos(pos3));
	display_spell_des_2(cor, id_spell_from_pos(pos3));
	RDW_DRWTXT(cor->window, cor->obj_spell.txt, NULL);
	RDW_DRWSPR(cor->window, cor->obj[17]->spr, NULL);
}
