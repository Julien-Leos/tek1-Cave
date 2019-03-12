/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** window handling resize and mouse coords
*/

#include "my_rpg.h"

void 	generate_mouse_coords(core_t *cor)
{
	sfVector2f 	new_mouse;

	cor->pos_mouse = sfMouse_getPositionRenderWindow(cor->window);
	new_mouse = sfRenderWindow_mapPixelToCoords(cor->window,
	cor->pos_mouse, cor->view);
	cor->pos_mouse.x = (int)new_mouse.x;
	cor->pos_mouse.y = (int)new_mouse.y;
}

void 	event_window_resize(core_t *cor)
{
	sfFloatRect new;

	if (cor->event.type == sfEvtResized) {
		new = (sfFloatRect) {0, 0, cor->event.size.width,
		cor->event.size.height};
		sfRenderWindow_setView(cor->window,
		sfView_createFromRect(new));
	}
}

sfRenderWindow 	*my_window_create(void)
{
	sfRenderWindow 	*window;
	sfVideoMode	mode;

	mode.width = LENGHT_WIN;
	mode.height = HEIGHT_WIN;
	mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(mode, "My RPG", sfDefaultStyle, NULL);
	sfRenderWindow_setKeyRepeatEnabled(window, sfFalse);
	sfRenderWindow_setFramerateLimit(window, 40);
	return (window);
}