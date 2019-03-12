/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

void	spell_heal(core_t *cor)
{
	float basic_dmg = my_percent(cor->ply.chrc[11], PERCENT);

	if (cor->btl.total_elem[0] < 3)
		return;
	cor->btl.total_elem[0] -= 3;
	anim_ply_handling(cor, 5, 2, 8);
	txt_state_ply_handling(cor, 0);
	cor->btl.dmg[1] += get_damage(basic_dmg, 0) * 0.6;
	cor->btl.life[0] += cor->btl.dmg[1];
	cor->obj_btl.dmg_txt[0] = my_itoa(cor->btl.dmg[1]);
}
