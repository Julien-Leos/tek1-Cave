/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** part 2 of event menu
*/

#include "my_rpg.h"

void 	event_change_keyboard_menu_main(core_t *cor, int *status)
{
	if (keyboard_button_click(cor, 0, sfKeyReturn, status))
		cor->state.in_menu = 1;
	if (keyboard_button_click(cor, 1, sfKeyReturn, status))
		cor->state.in_menu = 9;
	if (keyboard_button_click(cor, 2, sfKeyReturn, status))
		sfRenderWindow_close(cor->window);
}

void 	event_change_mouse_menu_main(core_t *cor, int *status)
{
	if (mouse_button_click(cor, 0, (V2F){450, 90}, status))
		cor->state.in_menu = 1;
	if (mouse_button_click(cor, 1, (V2F){450, 90}, status))
		cor->state.in_menu = 9;
	if (mouse_button_click(cor, 2, (V2F){450, 90}, status))
		sfRenderWindow_close(cor->window);
}

void 	preload_save(core_t *cor, int save, obj_t **obj)
{
	cor->state.in_menu = 3;
	cor->actual_scene = 2;
	cor->save_actual = save;
	load_save(cor, concat("save/",
	concat(my_getchar(save), "_save.save")));
	move_down(cor, obj, cor->ply.skin_move);
	move_down(cor, obj, cor->ply.skin_move);
	sfSound_play(cor->sound[3].obj);
	sfSound_stop(cor->sound[0].obj);
}

void event_change_keyboard_menu_play(core_t *cor, int *status, obj_t **obj)
{
	if (keyboard_button_click(cor, 3, sfKeyReturn, status))
		preload_save(cor, 1, obj);
	if (keyboard_button_click(cor, 4, sfKeyReturn, status))
		preload_save(cor, 2, obj);
	if (keyboard_button_click(cor, 5, sfKeyReturn, status))
		preload_save(cor, 3, obj);
}

void 	event_change_mouse_menu_play(core_t *cor, int *status, obj_t **obj)
{
	if (mouse_button_click(cor, 3, (V2F){450, 90}, status))
		preload_save(cor, 1, obj);
	if (mouse_button_click(cor, 4, (V2F){450, 90}, status))
		preload_save(cor, 2, obj);
	if (mouse_button_click(cor, 5, (V2F){450, 90}, status))
		preload_save(cor, 3, obj);
}
