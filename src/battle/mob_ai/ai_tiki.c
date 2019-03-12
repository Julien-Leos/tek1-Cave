/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

int	ai_tiki(core_t *cor)
{
	static int turn = 0;

	if (turn == 0) {
		turn = 1;
		return (11);
	} else {
		turn = 0;
		return (9);
	}
	(void)cor;
}
