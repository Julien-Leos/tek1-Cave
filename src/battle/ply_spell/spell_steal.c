/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

int	spell_steal_sub(core_t *cor)
{
	if (cor->btl.total_elem[0] < 2 || cor->btl.total_elem[5] < 2)
		return (1);
	cor->btl.total_elem[0] -= 2;
	cor->btl.total_elem[5] -= 2;
	anim_ply_handling(cor, 4, 3, 7);
	txt_state_ply_handling(cor, 2);
	return (0);
}

void	spell_steal(core_t *cor)
{
	float basic_dmg = my_percent(cor->ply.chrc[11], PERCENT);
	float strength = my_percent(cor->ply.chrc[8], PERCENT) * MULT;
	float critical = my_percent(cor->ply.chrc[9], PERCENT) * MULT;
	float armor = my_percent(cor->mob[cor->btl.mob_id].chrc[0], PERCENT);
	float defense = cor->mob[cor->btl.mob_id].chrc[1];
	float esquive = cor->mob[cor->btl.mob_id].chrc[4];

	if (spell_steal_sub(cor) == 1)
		return;
	if (miss_ply_handling(cor, esquive) == 1)
		return;
	cor->btl.dmg[0] += get_damage(basic_dmg, strength) * 1.5;
	defense_ply_handling(cor, armor, defense);
	critical_ply_handling(cor, critical, 2);
	cor->btl.life[1] -= cor->btl.dmg[0];
	cor->obj_btl.dmg_txt[1] = my_itoa(cor->btl.dmg[0]);
	cor->btl.dmg[1] = cor->btl.dmg[0] * 0.75;
	cor->btl.life[0] += cor->btl.dmg[1];
	cor->obj_btl.dmg_txt[0] = my_itoa(cor->btl.dmg[1]);
}
