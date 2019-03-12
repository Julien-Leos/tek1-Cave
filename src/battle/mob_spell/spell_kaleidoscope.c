/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

void	mob_spell_kaleidoscope(core_t *cor)
{
	sfSound_play(cor->sound[28].obj);
	cor->btl.state.anim_spell = 14;
	cor->btl.special[2]++;
	cor->mob[cor->btl.mob_id].power *= 2;
}
