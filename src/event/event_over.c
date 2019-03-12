/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** game over events
*/

#include "my_rpg.h"

void 	event_exit_over(core_t *cor, int *status)
{
	if (macro_button_click(sfKeySpace, status)) {
		cor->actual_scene = 1;
		cor->state.in_menu = 0;
		sfSound_play(cor->sound[0].obj);
		sfSound_stop(cor->sound[3].obj);
	}
	if (macro_button_click(sfKeyReturn, status)) {
		cor->actual_scene = 1;
		cor->state.in_menu = 0;
		sfSound_play(cor->sound[0].obj);
		sfSound_stop(cor->sound[3].obj);
	}
	if (sfMouse_isButtonPressed(sfMouseLeft)) {
		cor->actual_scene = 1;
		cor->state.in_menu = 0;
		sfSound_play(cor->sound[0].obj);
		sfSound_stop(cor->sound[3].obj);
	}
}

void 	event_over(core_t *cor)
{
	int 	status = 0;

	event_mouse_menu(cor);
	while (sfRenderWindow_pollEvent(cor->window, &(cor->event))) {
		if (cor->event.type == sfEvtClosed)
			sfRenderWindow_close(cor->window);
		event_keyboard_menu(cor, &status);
		event_exit_over(cor, &status);
	}
}
