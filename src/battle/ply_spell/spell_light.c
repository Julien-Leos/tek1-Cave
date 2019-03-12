/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

int	spell_light_sub(core_t *cor, int esquive)
{
	if (cor->btl.total_elem[4] < 4 || cor->btl.total_elem[3] < 2)
		return (1);
	cor->btl.total_elem[4] -= 4;
	cor->btl.total_elem[3] -= 2;
	anim_ply_handling(cor, 6, 2, 9);
	txt_state_ply_handling(cor, 2);
	if (miss_ply_handling(cor, esquive) == 1)
		return (1);
	return (0);
}

void	spell_light(core_t *cor)
{
	float basic_dmg = my_percent(cor->ply.chrc[8], PERCENT);
	float strength = my_percent(cor->ply.chrc[8], PERCENT) * MULT;
	float critical = my_percent(cor->ply.chrc[9], PERCENT) * MULT;
	float armor = my_percent(cor->mob[cor->btl.mob_id].chrc[0], PERCENT);
	float defense = cor->mob[cor->btl.mob_id].chrc[1];
	float esquive = cor->mob[cor->btl.mob_id].chrc[4];

	if (spell_light_sub(cor, esquive) == 1)
		return;
	cor->btl.dmg[0] += get_damage(basic_dmg, strength);
	defense_ply_handling(cor, armor, defense);
	critical_ply_handling(cor, critical, 2);
	cor->btl.life[1] -= cor->btl.dmg[0];
	cor->obj_btl.dmg_txt[1] = my_itoa(cor->btl.dmg[0]);
	cor->btl.dmg[1] += get_damage(basic_dmg, 0);
	cor->btl.life[0] += cor->btl.dmg[1];
	cor->obj_btl.dmg_txt[0] = my_itoa(cor->btl.dmg[1]);
	cor->btl.turn_state = -1;
	display_battle_dice_face(cor);
}
