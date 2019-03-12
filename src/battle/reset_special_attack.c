/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

void	reset_special_sword_psy(core_t *cor)
{
	if (cor->btl.special[1] != 0) {
		if (cor->btl.special[1] == 1)
			cor->mob[cor->btl.mob_id].chrc[3] -= 100;
		cor->btl.special[1]--;
	}
}

void	reset_special_tornado(core_t *cor)
{
	if (cor->btl.special[3] == 1) {
		cor->mob[cor->btl.mob_id].chrc[4] -= 50;
		cor->btl.special[3] = 0;
	}
}

void	reset_special_frog(core_t *cor)
{
	for (; cor->btl.special[0] > 0; cor->btl.special[0]--) {
		cor->mob[cor->btl.mob_id].chrc[0] /= 0.9;
		cor->ply.chrc[6] /= 1.1;
	}
}

void	reset_special_kaleidoscope(core_t *cor)
{
	for (; cor->btl.special[2] > 0; cor->btl.special[2]--)
		cor->mob[cor->btl.mob_id].power /= 2;
}

void	reset_special_blindy(core_t *cor)
{
	for (; cor->btl.special[4] > 0; cor->btl.special[4]--)
		for (int i = 6; i < 12; i++)
			cor->ply.chrc[i] /= 0.9;
}
