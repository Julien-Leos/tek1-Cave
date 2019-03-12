/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** semi_global
*/

#include "my_rpg.h"

int	my_cheat(int nb)
{
	static int i = 0;

	if (nb == 5)
		return (i);
	i = nb;
	return (0);
}
