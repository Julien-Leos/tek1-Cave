/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

int	critical_mob_handling(core_t *cor, float critical)
{
	if (get_critical(critical) == 1) {
		cor->btl.dmg[1] *= 2;
		cor->obj_btl.color_txt[0] = CLR_FRRGBA(255, 215, 0, 255);
		return (1);
	}
	return (0);
}

int	miss_mob_handling(core_t *cor, float esquive)
{
	if (get_miss(esquive) == 1) {
		cor->btl.state.anim_main = 4;
		cor->btl.dmg[1] = 0;
		cor->obj_btl.dmg_txt[0] = "MISS";
		return (1);
	}
	return (0);
}

int	defense_mob_handling(core_t *cor, float armor, float defense)
{
	if ((cor->btl.dmg[1] -= get_defense(armor, defense)) < 0) {
		cor->btl.dmg[1] = 0;
		return (1);
	}
	return (0);
}

void	txt_state_mob_handling(core_t *cor, int txt_state)
{
	if (txt_state == 0)
		cor->obj_btl.color_txt[0] = CLR_FRRGBA(180, 0, 0, 255);
	else if (txt_state == 1)
		cor->obj_btl.color_txt[1] = CLR_FRRGBA(0, 180, 0, 255);
	else {
		cor->obj_btl.color_txt[0] = CLR_FRRGBA(180, 0, 0, 255);
		cor->obj_btl.color_txt[1] = CLR_FRRGBA(0, 180, 0, 255);
	}
}

void	anim_mob_handling(core_t *cor, int spell_id, int snd_id)
{
	sfSound_play(cor->sound[snd_id].obj);
	cor->btl.state.anim_ennemy = 1;
	cor->btl.state.anim_spell = spell_id;
}
