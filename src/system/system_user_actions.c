/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** user interaction with keyboard and mouse
*/

#include "my_rpg.h"

int keyboard_button_click(core_t *cor, int id, sfKeyCode key, int *status)
{
	if (sfKeyboard_isKeyPressed(key) && cor->button[id].state == 1 &&
	cor->button[id].belong_menu == cor->state.in_menu && *status != 1) {
		sfSound_play(cor->sound[2].obj);
		*status = 1;
		return (1);
	}
	return (0);
}

int mouse_button_click(core_t *cor, int id, sfVector2f rect, int *status)
{
	if (sfMouse_isButtonPressed(sfMouseLeft) && *status != 1 &&
	mouse_is_hover(cor->button[id].spr, cor->pos_mouse, rect) &&
	cor->button[id].belong_menu == cor->state.in_menu &&
	cor->button[id].state == 1) {
		sfSound_play(cor->sound[2].obj);
		*status = 1;
		return (1);
	}
	return (0);
}

int 	macro_button_click(sfKeyCode key, int *status)
{
	if (sfKeyboard_isKeyPressed(key) && *status != 1) {
		*status = 1;
		return (1);
	}
	return (0);
}