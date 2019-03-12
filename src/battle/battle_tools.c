/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

int	is_ply_dmg_displayed(core_t *cor)
{
	if (cor->btl.dmg_cycle[0] != 0)
		return (1);
	return (0);
}

int	is_enm_dmg_displayed(core_t *cor)
{
	if (cor->btl.dmg_cycle[1] != 0)
		return (1);
	return (0);
}

void	is_player_dead(core_t *cor)
{
	if (cor->btl.life[0] <= 0 && cor->btl.msg_cycle == 1) {
		sfSound_play(cor->sound[21].obj);
		reset_special_kaleidoscope(cor);
		reset_special_blindy(cor);
	}
	if (cor->btl.life[0] <= 0) {
		cor->btl.state.anim_main = 5;
		cor->btl.turn_state = 2;
		display_loose_screen(cor);
	}
}

void	is_ennemy_dead(core_t *cor)
{
	if (cor->btl.life[1] <= 0 && cor->btl.msg_cycle == 1) {
		sfSound_play(cor->sound[20].obj);
		reset_special_kaleidoscope(cor);
		reset_special_blindy(cor);
	}
	if (cor->btl.life[1] <= 0) {
		cor->btl.state.anim_main = 6;
		cor->btl.state.anim_ennemy = 3;
		cor->btl.turn_state = 2;
		display_win_screen(cor);
	}
}

int	is_all_anim_ended(core_t *cor)
{
	if (cor->btl.state.anim_spell == 0 && cor->btl.state.anim_ennemy == 0
	&& is_enm_dmg_displayed(cor) == 0 && is_ply_dmg_displayed(cor) == 0)
		return (1);
	return (0);
}
