/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

int	recup_nbr_item(core_t *cor, int id)
{
	int count = 0;

	for (int i = 0; i < NB_INVENTORY_CASE; i++)
		if (cor->inv[i] == id)
			count++;
	return (count);
}

void	add_item(core_t *cor, int id)
{
	for (int i = 0; i < NB_INVENTORY_CASE; i++) {
		if (cor->inv[i] == 0) {
			cor->inv[i] = id;
			return;
		}
	}
}

void	delete_item(core_t *cor, int id)
{
	for (int i = 0; i < NB_INVENTORY_CASE; i++) {
		if (cor->inv[i] == id) {
			cor->inv[i] = 0;
			return;
		}
	}
}
