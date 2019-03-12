/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

int	get_damage(float attack, float strength)
{
	float random = rand() % 50;
	float dmg = powf(attack, 1.5) * 480 + 100;

	dmg *= 1 + (random / 5 - 5) / 100;
	dmg *= 1 + ((float)strength / 100);
	return (dmg);
}

int	get_defense(float armor, float defense)
{
	float random = rand() % 50;
	float def = powf(armor, 1.5) * 480;

	def *= 1 + (random / 5 - 5) / 100;
	def *= 1 + ((float)defense / 100);
	return (def);
}

int	get_critical(float critical)
{
	if (rand() % 100 < critical)
		return (1);
	return (0);
}

int	get_miss(float esquive)
{
	if (rand() % 100 < esquive)
		return (1);
	return (0);
}

int	get_chance(float luck)
{
	if (rand() % 100 < luck)
		return (1);
	return (0);
}
