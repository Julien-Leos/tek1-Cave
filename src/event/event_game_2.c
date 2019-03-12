/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** event mouse/keyboard for menu scene
*/

#include "my_rpg.h"

void 	event_change_keyboard_player_main(core_t *cor, int *status)
{
	if (keyboard_button_click(cor, 9, sfKeyReturn, status))
		cor->state.in_menu = 4;
	if (keyboard_button_click(cor, 10, sfKeyReturn, status)) {
		cor->state.in_menu = 6;
		SPR_SETPOS(cor->obj[17]->spr, (V2F){100, 256});
		SPR_SETSCL(cor->obj[17]->spr, (V2F){1, 1});
	}
	if (keyboard_button_click(cor, 11, sfKeyReturn, status))
		cor->state.in_menu = 7;
}

void 	event_change_mouse_player_main(core_t *cor, int *status)
{
	if (mouse_button_click(cor, 9, (V2F){450, 90}, status))
		cor->state.in_menu = 4;
	if (mouse_button_click(cor, 10, (V2F){450, 90}, status))
		cor->state.in_menu = 6;
	if (mouse_button_click(cor, 11, (V2F){450, 90}, status))
		cor->state.in_menu = 7;
}

void 	event_change_keyboard_control_main(core_t *cor, int *status)
{
	if (keyboard_button_click(cor, 12, sfKeyReturn, status))
		cor->state.in_menu = 3;
	if (keyboard_button_click(cor, 13, sfKeyReturn, status)) {
		sfSound_play(cor->sound[0].obj);
		sfSound_stop(cor->sound[3].obj);
		cor->state.in_menu = 0;
		cor->actual_scene = 1;
		cor->text_box = NULL;
	}
}

void 	event_change_mouse_control_main(core_t *cor, int *status)
{
	if (mouse_button_click(cor, 12, (V2F){450, 90}, status))
		cor->state.in_menu = 3;
	if (mouse_button_click(cor, 13, (V2F){450, 90}, status)) {
		sfSound_play(cor->sound[0].obj);
		sfSound_stop(cor->sound[3].obj);
		cor->state.in_menu = 0;
		cor->actual_scene = 1;
		cor->text_box = NULL;
	}
}

void 	event_change_mouse_return(core_t *cor, int *status)
{
	if (mouse_button_click(cor, 14, (V2F){250, 90}, status))
		cor->state.in_menu = 3;
	if (mouse_button_click(cor, 15, (V2F){450, 90}, status))
		cor->state.in_menu = 3;
	if (mouse_button_click(cor, 16, (V2F){450, 90}, status))
		cor->state.in_menu = 3;
}
