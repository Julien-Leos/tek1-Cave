/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** user interaction with UI : keyboard and mouse
*/

#include "my_rpg.h"

int mouse_is_hover(sfSprite *elem, sfVector2i pos_click, sfVector2f size)
{
	return (pos_click.x < sfSprite_getPosition(elem).x + size.x &&
	pos_click.x > sfSprite_getPosition(elem).x &&
	pos_click.y < sfSprite_getPosition(elem).y + size.y &&
	pos_click.y > sfSprite_getPosition(elem).y);
}

void 	refresh_state_buttons(core_t *cor, int next, int select)
{
	for (int i = 0; i < NB_BUTTONS && next != 0; i++) {
		if (cor->button[i].state == 1 &&
		cor->button[i + next].belong_menu == cor->state.in_menu) {
			cor->button[i + next].state = 1;
			cor->button[i].state = 0;
			break;
		}
	}
	for (int i = 0; i < NB_BUTTONS && next == 0; i++) {
		if (cor->button[i].state == 1 &&
		cor->button[i].belong_menu == cor->state.in_menu &&
		select != i)
			cor->button[i].state = 0;
		if (select == i)
			cor->button[i].state = 1;
	}
}

void 	event_keyboard_menu(core_t *cor, int *status)
{
	if (*status == 1)
		return;
	if (sfKeyboard_isKeyPressed(sfKeyUp) && cor->state.in_menu != 3) {
		sfSound_play(cor->sound[1].obj);
		refresh_state_buttons(cor, -1, 0);
		*status = 1;
	}
	if (sfKeyboard_isKeyPressed(sfKeyDown) && cor->state.in_menu != 3) {
		sfSound_play(cor->sound[1].obj);
		refresh_state_buttons(cor, 1, 0);
		*status = 1;
	}
}

void 	event_mouse_menu(core_t *cor)
{
	for (int i = 0; i < NB_BUTTONS; i++) {
		if (cor->button[i].state == 1)
			continue;
		if (mouse_is_hover(cor->button[i].spr, cor->pos_mouse,
		(V2F){375, 90}) &&
		cor->button[i].belong_menu == cor->state.in_menu) {
			refresh_state_buttons(cor, 0, i);
		}
	}
}

void 	change_save_sprite(core_t *cor)
{
	if (!save_exist("save/1_save.save")) {
		cor->button[3].spr = sfSprite_copy(cor->obj[10]->spr);
		sfSprite_setPosition(cor->button[3].spr, (V2F){500, 480});
		cor->button[3].top = 900;
	}
	my_get_next_line(-42);
	if (!save_exist("save/2_save.save")) {
		cor->button[4].spr = sfSprite_copy(cor->obj[11]->spr);
		sfSprite_setPosition(cor->button[4].spr, (V2F){500, 600});
		cor->button[4].top = 990;
	}
	my_get_next_line(-42);
	if (!save_exist("save/3_save.save")) {
		cor->button[5].spr = sfSprite_copy(cor->obj[12]->spr);
		sfSprite_setPosition(cor->button[5].spr, (V2F){500, 720});
		cor->button[5].top = 1080;
	}
	my_get_next_line(-42);
}