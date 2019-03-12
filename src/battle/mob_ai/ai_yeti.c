/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

int	ai_yeti(core_t *cor)
{
	static int count = 0;
	int life_mob_max = cor->mob[cor->btl.mob_id].life;
	float actual_mob_life = my_percent(cor->btl.life[1], life_mob_max);

	if (actual_mob_life <= 40 || actual_mob_life >= 80 || count >= 2)
		return (10);
	else {
		count++;
		return (14);
	}
}
