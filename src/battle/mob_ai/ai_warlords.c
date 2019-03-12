/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

int	ai_warlords_sub(int actual_mob_life)
{
	float random = 0;

	if (actual_mob_life <= 20)
		return (13);
	else if (actual_mob_life <= 80) {
		random = rand() % 2;
		return ((random == 0) ? 13 : 12);
	} else
		return (12);
}

int	ai_warlords(core_t *cor)
{
	int life_mob_max = cor->mob[cor->btl.mob_id].life;
	float actual_mob_life = my_percent(cor->btl.life[1], life_mob_max);
	int life_ply_max = cor->ply.life;
	float actual_ply_life = my_percent(cor->btl.life[0], life_ply_max);

	if (actual_ply_life <= 30)
		return (12);
	return (ai_warlords_sub(actual_mob_life));
}
