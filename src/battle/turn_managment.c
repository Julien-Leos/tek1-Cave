/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

void	ennemy_turn(core_t *cor)
{
	if (is_all_anim_ended(cor) == 1)
		ai_ennemy(cor);
}

void	player_turn(core_t *cor)
{
	if (cor->btl.state.anim_spell == 0 && cor->btl.state.anim_ennemy == 0)
		cor->btl.turn_state = 0;
	else
		cor->btl.turn_state = 4;
}
