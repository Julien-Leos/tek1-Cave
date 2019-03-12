/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

int	ai_gnomes(core_t *cor)
{
	if (my_percent(cor->btl.life[1], cor->mob[cor->btl.mob_id].life) <= 50)
		return (16);
	else
		return (11);
}
