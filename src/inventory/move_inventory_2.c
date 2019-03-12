/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** event mouse/keyboard for menu scene
*/

#include "my_rpg.h"

void	move_inv_up(core_t *cor, int *key, int *status)
{
	if ((*key % 3 == 0 && *key > 13) || *key == 0) {
		if (cor->obj_inv.which_select == 0)
			move_select_item(cor, 0, -70, status);
		else
			move_select_armor(cor, -1, status);
	}
	*key += 1;
}

void	move_inv_down(core_t *cor, int *key, int *status)
{
	if ((*key % 3 == 0 && *key > 13) || *key == 0) {
		if (cor->obj_inv.which_select == 0)
			move_select_item(cor, 0, 70, status);
		else
			move_select_armor(cor, 1, status);
	}
	*key += 1;
}

void	move_inv_left(core_t *cor, int *key, int *status)
{
	if ((*key % 3 == 0 && *key > 13) || *key == 0) {
		if (cor->obj_inv.which_select == 0)
			move_select_item(cor, -68, 0, status);
	}
	*key += 1;
}

void	move_inv_right(core_t *cor, int *key, int *status)
{
	if ((*key % 3 == 0 && *key > 13) || *key == 0) {
		if (cor->obj_inv.which_select == 0)
			move_select_item(cor, 68, 0, status);
	}
	*key += 1;
}
