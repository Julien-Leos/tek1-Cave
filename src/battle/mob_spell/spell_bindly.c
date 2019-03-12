/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

void	mob_spell_bindly(core_t *cor)
{
	sfSound_play(cor->sound[31].obj);
	cor->btl.state.anim_spell = 17;
	cor->btl.special[4]++;
	for (int i = 6; i < 12; i++)
		cor->ply.chrc[i] *= 0.9;
}
