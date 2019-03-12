/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

void	display_battle_obj(core_t *cor)
{
	display_battle_background(cor);
	display_battle_nbr_elements(cor);
	if (cor->button[18].state == 1)
		display_battle_spell(cor);
	if (cor->button[19].state == 1)
		display_battle_object(cor);
	display_battle_characters(cor);
	display_spell_animation(cor);
}

void	display_battle_top_stripe(core_t *cor)
{
	float chance = my_percent(cor->ply.chrc[11], PERCENT);

	if (cor->obj_btl.dice_cycle[0] > 0 &&
	cor->obj_btl.dice_cycle[0] < 85 && cor->btl.turn_state != 2) {
		if (cor->obj_btl.dice_cycle[0] <= 50)
			randomise_dice_launch(cor);
		display_battle_dice_face(cor);
	} else if (cor->obj_btl.dice_cycle[0] == 85) {
		display_battle_dice_face(cor);
		if (get_chance(chance) == 1) {
			cor->btl.turn_state = -1;
			display_battle_dice_face(cor);
		}
	} else
		display_battle_life(cor);
}

void	display_battle(core_t *cor)
{
	display_battle_obj(cor);
	if (cor->btl.turn_state == -2)
		display_start_screen(cor);
	is_player_dead(cor);
	is_ennemy_dead(cor);
	display_damage_player(cor, cor->obj_btl.color_txt[0]);
	display_damage_ennemi(cor, cor->obj_btl.color_txt[1]);
	if (cor->btl.turn_state == 1)
		ennemy_turn(cor);
	display_battle_top_stripe(cor);
}
