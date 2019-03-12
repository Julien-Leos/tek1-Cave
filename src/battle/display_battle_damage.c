/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

int	change_dmg_cycle(core_t *cor, int i)
{
	if (cor->btl.dmg[i] == -1)
		return (1);
	if (cor->btl.dmg_cycle[i] == 30) {
		cor->btl.dmg_cycle[i] = 0;
		cor->btl.dmg[i] = -1;
		return (1);
	} else
		cor->btl.dmg_cycle[i]++;
	return (0);
}

void	display_damage_ennemi(core_t *cor, sfColor color)
{
	V2F pos = {0, 0};
	int size = 0;

	if (change_dmg_cycle(cor, 0) == 1)
		return;
	pos.x = 1250 - cor->btl.dmg_cycle[0] / 5;
	pos.y = 450 - cor->btl.dmg_cycle[0] * 5;
	size = 55 - (cor->btl.dmg_cycle[0] - 15);
	if (cor->btl.dmg_cycle[0] < 15) {
		color.a = 255;
		TXT_SETCLR(cor->obj_btl.txt, color);
		TXT_SETSIZ(cor->obj_btl.txt, 55);
	} else {
		color.a = 255 - (cor->btl.dmg_cycle[0] - 15) * 17;
		TXT_SETCLR(cor->obj_btl.txt, color);
		TXT_SETSIZ(cor->obj_btl.txt, size);
	}
	TXT_SETSTR(cor->obj_btl.txt, cor->obj_btl.dmg_txt[1]);
	TXT_SETPOS(cor->obj_btl.txt, pos);
	RDW_DRWTXT(cor->window, cor->obj_btl.txt, NULL);
}

void	display_damage_player(core_t *cor, sfColor color)
{
	V2F pos = {0, 0};
	int size = 0;

	if (change_dmg_cycle(cor, 1) == 1)
		return;
	pos.x = 200 - cor->btl.dmg_cycle[1] / 5;
	pos.y = 450 - cor->btl.dmg_cycle[1] * 5;
	size = 55 - (cor->btl.dmg_cycle[1] - 15);
	if (cor->btl.dmg_cycle[1] < 15) {
		color.a = 255;
		TXT_SETCLR(cor->obj_btl.txt, color);
		TXT_SETSIZ(cor->obj_btl.txt, 55);
	} else {
		color.a = 255 - (cor->btl.dmg_cycle[1] - 15) * 17;
		TXT_SETCLR(cor->obj_btl.txt, color);
		TXT_SETSIZ(cor->obj_btl.txt, size);
	}
	TXT_SETSTR(cor->obj_btl.txt, cor->obj_btl.dmg_txt[0]);
	TXT_SETPOS(cor->obj_btl.txt, pos);
	RDW_DRWTXT(cor->window, cor->obj_btl.txt, NULL);
}
