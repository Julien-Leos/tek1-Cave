/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

int	ai_lyon(core_t *cor)
{
	int life_mob_max = cor->mob[cor->btl.mob_id].life;
	float actual_mob_life = my_percent(cor->btl.life[1], life_mob_max);

	if (actual_mob_life <= 40 || cor->ply.chrc[6] <= 25)
		return (18);
	else
		return (17);
}
