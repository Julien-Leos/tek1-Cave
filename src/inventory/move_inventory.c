/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** event mouse/keyboard for menu scene
*/

#include "my_rpg.h"

void	move_inventory_2(core_t *cor, int *status, int key[4])
{
	if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
		move_inv_left(cor, &key[2], status);
	} else
		key[2] = 0;
	if (sfKeyboard_isKeyPressed(sfKeyRight)) {
		move_inv_right(cor, &key[3], status);
	} else
		key[3] = 0;
}

void	move_inventory(core_t *cor, int *status)
{
	static int key[4] = {0, 0, 0, 0};

	if (sfKeyboard_isKeyPressed(sfKeyUp)) {
		move_inv_up(cor, &key[0], status);
	} else
		key[0] = 0;
	if (sfKeyboard_isKeyPressed(sfKeyDown)) {
		move_inv_down(cor, &key[1], status);
	} else
		key[1] = 0;
	move_inventory_2(cor, status, key);
}
