/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

int	ai_centaur(core_t *cor)
{
	float random = 0;

	if (my_percent(cor->btl.life[1], cor->mob[cor->btl.mob_id].life) <= 30)
		random = rand() % 2;
	else
		random =  rand() % 4;
	if (random == 0)
		return (15);
	return (9);
}
