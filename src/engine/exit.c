/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** lib_fonc
*/

#include "my_rpg.h"

int	my_exit(int i)
{
	static int nb = 0;

	if (i != 0)
		nb = i;
	return (nb);
}