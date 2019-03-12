/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** event mouse/keyboard for menu scene
*/

#include "my_rpg.h"

void 	event_change_keyboard_settings_tweaks(core_t *cor, int *status)
{
	if (keyboard_button_click(cor, 21, sfKeyReturn, status))
		change_music_volume(cor);
	if (keyboard_button_click(cor, 22, sfKeyReturn, status))
		change_ui_volume(cor);
	if (keyboard_button_click(cor, 23, sfKeyReturn, status))
		change_hero_skin(cor);
}

void 	event_change_keyboard_menu_settings(core_t *cor, int *status)
{
	if (keyboard_button_click(cor, 24, sfKeyReturn, status))
		cor->state.in_menu = 0;
	if (keyboard_button_click(cor, 6, sfKeyReturn, status))
		cor->state.in_menu = 0;
}

void 	event_change_mouse_settings_tweaks(core_t *cor, int *status)
{
	if (mouse_button_click(cor, 21, (V2F){450, 90}, status))
		change_music_volume(cor);
	if (mouse_button_click(cor, 22, (V2F){450, 90}, status))
		change_ui_volume(cor);
	if (mouse_button_click(cor, 23, (V2F){450, 90}, status))
		change_hero_skin(cor);
}

void 	event_change_mouse_menu_settings(core_t *cor, int *status)
{
	if (mouse_button_click(cor, 24, (V2F){450, 90}, status))
		cor->state.in_menu = 0;
	if (mouse_button_click(cor, 6, (V2F){450, 90}, status))
		cor->state.in_menu = 0;
}

void 	event_menu(core_t *cor, obj_t **obj)
{
	int 	status = 0;

	event_mouse_menu(cor);
	while (sfRenderWindow_pollEvent(cor->window, &(cor->event))) {
		if (cor->event.type == sfEvtClosed)
			sfRenderWindow_close(cor->window);
		event_keyboard_menu(cor, &status);
		event_change_keyboard_menu_main(cor, &status);
		event_change_mouse_menu_main(cor, &status);
		event_change_keyboard_menu_play(cor, &status, obj);
		event_change_mouse_menu_play(cor, &status, obj);
		event_change_keyboard_settings_tweaks(cor, &status);
		event_change_mouse_settings_tweaks(cor, &status);
		event_change_keyboard_menu_settings(cor, &status);
		event_change_mouse_menu_settings(cor, &status);
	}
}
