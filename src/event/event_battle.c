/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** event for battle scene
*/

#include "my_rpg.h"

void	event_battle_return(core_t *cor, int *status)
{
	int state = 0;

	if (macro_button_click(sfKeyReturn, status) &&
	cor->btl.turn_state == 0) {
		if (cor->button[18].state == 1 &&
		is_all_anim_ended(cor) == 1) {
			state = 1;
			select_spell(cor);
		}
		if (cor->button[19].state == 1 && state == 0) {
			state = 1;
			select_conso(cor);
		}
		if (cor->button[20].state == 1 && state == 0) {
			cor->btl.turn_state = 1;
			reset_special_tornado(cor);
		}
	}
}

void	event_battle_right(core_t *cor, V2F pos, int *status)
{
	V2F new_pos = {0, pos.y};

	if (macro_button_click(sfKeyRight, status)) {
		if (cor->obj_btl.which_menu == 1 && pos.x < 1440) {
			new_pos.x = pos.x + 128;
			SPR_SETPOS(cor->obj[17]->spr, new_pos);
		} else if (cor->obj_btl.which_menu == 0 && pos.x < 1568) {
			new_pos.x = pos.x + 256;
			SPR_SETPOS(cor->obj[17]->spr, new_pos);
		} else
			return;
	}
}

void	event_battle_left(core_t *cor, V2F pos, int *status)
{
	V2F new_pos = {0, pos.y};

	if (macro_button_click(sfKeyLeft, status)) {
		if (cor->obj_btl.which_menu == 1 && pos.x > 1056) {
			new_pos.x = pos.x - 128;
			SPR_SETPOS(cor->obj[17]->spr, new_pos);
		} else if (cor->obj_btl.which_menu == 0 && pos.x > 800) {
			new_pos.x = pos.x - 256;
			SPR_SETPOS(cor->obj[17]->spr, new_pos);
		} else
			return;
	}
}

void 	event_battle(core_t *cor)
{
	int	status = 0;
	V2F pos = SPR_GETPOS(cor->obj[17]->spr);

	event_mouse_menu(cor);
	while (sfRenderWindow_pollEvent(cor->window, &(cor->event))) {
		if (cor->event.type == sfEvtClosed)
			sfRenderWindow_close(cor->window);
		event_battle_right(cor, pos, &status);
		event_battle_left(cor, pos, &status);
		event_battle_return(cor, &status);
		if (mouse_button_click(cor, 20, (V2F){450, 90}, &status)) {
			cor->btl.turn_state = 1;
			reset_special_tornado(cor);
		}
		event_keyboard_menu(cor, &status);
	}
}
