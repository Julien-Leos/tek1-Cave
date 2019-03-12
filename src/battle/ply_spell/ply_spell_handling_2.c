/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

void	anim_ply_handling(core_t *cor, int spell_id, int anim_id, int snd_id)
{
	sfSound_play(cor->sound[snd_id].obj);
	cor->btl.state.anim_ennemy = 2;
	cor->btl.state.anim_spell = spell_id;
	cor->btl.state.anim_main = anim_id;
}
