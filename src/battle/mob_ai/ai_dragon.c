/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

int	ai_dragon(core_t *cor)
{
	static int turn = 0;

	(void)cor;
	if (turn == 0) {
		turn = 1;
		return (12);
	} else {
		turn = 0;
		return (14);
	}
}
