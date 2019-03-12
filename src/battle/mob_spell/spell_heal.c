/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

void	mob_spell_heal(core_t *cor)
{
	float basic_dmg = my_percent(cor->mob[cor->btl.mob_id].power, PERCENT);

	anim_mob_handling(cor, 16, 30);
	txt_state_mob_handling(cor, 1);
	cor->btl.dmg[0] += get_damage(basic_dmg, 0) * 2;
	cor->btl.life[1] += cor->btl.dmg[0];
	cor->obj_btl.dmg_txt[1] = my_itoa(cor->btl.dmg[0]);
}
