/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

void	mob_spell_tornado(core_t *cor)
{
	float basic_dmg = my_percent(cor->mob[cor->btl.mob_id].power, PERCENT);
	float strength = cor->mob[cor->btl.mob_id].chrc[2];
	float critical = cor->mob[cor->btl.mob_id].chrc[3];
	float armor = my_percent(cor->ply.chrc[6], PERCENT);
	float defense = my_percent(cor->ply.chrc[7], PERCENT) * MULT;
	float esquive = my_percent(cor->ply.chrc[10], PERCENT) * MULT;

	anim_mob_handling(cor, 15, 29);
	txt_state_mob_handling(cor, 0);
	if (miss_mob_handling(cor, esquive) == 1)
		return;
	cor->btl.state.anim_main = 1;
	cor->btl.dmg[1] += get_damage(basic_dmg, strength);
	defense_mob_handling(cor, armor, defense);
	critical_mob_handling(cor, critical);
	cor->btl.life[0] -= cor->btl.dmg[1];
	cor->obj_btl.dmg_txt[0] = my_itoa(cor->btl.dmg[1]);
	if (cor->btl.special[3] == 0)
		cor->mob[cor->btl.mob_id].chrc[4] += 50;
	cor->btl.special[3] = 1;
}
