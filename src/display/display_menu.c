/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** menu display
*/

#include "my_rpg.h"

void 	change_state_buttons(core_t *cor, int i, int state)
{
	int 	x = cor->button[i].top + state * 30;
	sfIntRect rect = (sfIntRect){0, x, 150, 30};

	sfSprite_setTextureRect(cor->button[i].spr, rect);
}

void 	display_buttons(core_t *cor)
{
	for (int i = 0; i < NB_BUTTONS; i++) {
		if (cor->state.in_menu == cor->button[i].belong_menu) {
			change_state_buttons(cor, i, cor->button[i].state);
			sfRenderWindow_drawSprite(cor->window,
			cor->button[i].spr, NULL);
		}
	}
}

void 	display_menu(core_t *cor)
{
	static sfRectangleShape *bg = NULL;

	bg = (bg == NULL) ? sfRectangleShape_create() : bg;
	sfRectangleShape_setSize(bg, (sfVector2f) {500, HEIGHT_WIN});
	sfRectangleShape_setFillColor(bg, (sfColor) {77, 63, 154, 127});
	sfRectangleShape_setPosition(bg, (sfVector2f) {470, 0});
	sfRenderWindow_clear(cor->window, sfBlack);
	sfSprite_setScale(cor->obj[0]->spr, (V2F){5.41, 5.41});
	sfRenderWindow_drawSprite(cor->window, cor->obj[0]->spr, NULL);
	particle_menu(cor);
	sfRenderWindow_drawRectangleShape(cor->window, bg, NULL);
	if (cor->state.in_menu == 9) {
		SPR_SETPOS(cor->obj[14]->spr, (V2F){620, 237});
		SPR_SETSCL(cor->obj[14]->spr, (V2F){3, 3});
		sfSprite_setTextureRect(cor->obj[14]->spr,
		(sfIntRect){512, 0, 64, 64});
		RDW_DRWSPR(cor->window, cor->obj[14]->spr, NULL);
	}
}

void 	display_pause(core_t *cor)
{
	static sfRectangleShape *bg = NULL;

	bg = (bg == NULL) ? sfRectangleShape_create() : bg;
	sfRectangleShape_setSize(bg, (sfVector2f) {500, HEIGHT_WIN});
	sfRectangleShape_setFillColor(bg, (sfColor) {77, 63, 154, 157});
	sfRectangleShape_setPosition(bg, (sfVector2f) {370, 0});
	sfRenderWindow_drawRectangleShape(cor->window, bg, NULL);
}
