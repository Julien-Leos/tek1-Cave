/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** event mouse/keyboard for menu scene
*/

#include "my_rpg.h"

void 	event_change_inventory_pannel(core_t *cor, int *status)
{
	if (macro_button_click(sfKeyS, status) && cor->state.in_menu == 4)
		cor->obj_inv.pannel = (cor->obj_inv.pannel == 0) ? 1 : 0;
	if (mouse_button_click(cor, 17, (V2F){250, 90}, status))
		cor->obj_inv.pannel = (cor->obj_inv.pannel == 0) ? 1 : 0;
}

void 	event_change_quest_menu(core_t *cor, int *status)
{
	if (cor->state.in_menu == 7 &&
	sfKeyboard_isKeyPressed(sfKeyReturn) && *status == 0) {
		cor->state.in_quest = cor->state.in_submenu - 8;
		*status = 1;
	}
	if (cor->state.in_menu == 7 && sfMouse_isButtonPressed(sfMouseLeft) &&
	cor->pos_mouse.x > 106 && cor->pos_mouse.x < 1812 && *status == 0) {
		cor->state.in_quest = (cor->pos_mouse.y > 192 &&
		cor->pos_mouse.y < 341) ? 0 : cor->state.in_quest;
		cor->state.in_quest = (cor->pos_mouse.y > 366 &&
		cor->pos_mouse.y < 515) ? 1 : cor->state.in_quest;
		cor->state.in_quest = (cor->pos_mouse.y > 540 &&
		cor->pos_mouse.y < 689) ? 2 : cor->state.in_quest;
		cor->state.in_quest = (cor->pos_mouse.y > 716 &&
		cor->pos_mouse.y < 865) ? 3 : cor->state.in_quest;
	}
}

void 	event_hover_quest_menu(core_t *cor)
{
	if (cor->state.in_menu == 7 &&
	cor->pos_mouse.x > 106 && cor->pos_mouse.x < 1812) {
		cor->state.in_submenu = (cor->pos_mouse.y > 192 &&
		cor->pos_mouse.y < 341) ? 8 : cor->state.in_submenu;
		cor->state.in_submenu = (cor->pos_mouse.y > 366 &&
		cor->pos_mouse.y < 515) ? 9 : cor->state.in_submenu;
		cor->state.in_submenu = (cor->pos_mouse.y > 540 &&
		cor->pos_mouse.y < 689) ? 10 : cor->state.in_submenu;
		cor->state.in_submenu = (cor->pos_mouse.y > 716 &&
		cor->pos_mouse.y < 865) ? 11 : cor->state.in_submenu;
	}
}

void 	event_change_submenu_spell_menu(core_t *cor, int **status)
{
	if (sfKeyboard_isKeyPressed(sfKeyLeft) && **status == 0) {
		sfSound_play(cor->sound[1].obj);
		**status = 1;
		cor->state.in_submenu += (cor->state.in_menu == 6) ? 1 : 0;
	}
	if (sfKeyboard_isKeyPressed(sfKeyRight) && **status == 0) {
		sfSound_play(cor->sound[1].obj);
		**status = 1;
		cor->state.in_submenu -= (cor->state.in_menu == 6) ? 1 : 0;
	}
}

void 	event_change_submenu_quest_spell_menu(core_t *cor, int *status)
{
	if (cor->state.in_menu != 6 && cor->state.in_menu != 7)
		return;
	if (sfKeyboard_isKeyPressed(sfKeyDown) && *status == 0) {
		sfSound_play(cor->sound[1].obj);
		*status = 1;
		cor->state.in_submenu += (cor->state.in_menu == 6) ? 4 : 1;
	}
	if (sfKeyboard_isKeyPressed(sfKeyUp) && *status == 0) {
		sfSound_play(cor->sound[1].obj);
		*status = 1;
		cor->state.in_submenu -= (cor->state.in_menu == 6) ? 4 : 1;
	}
	event_change_submenu_spell_menu(cor, &status);
}
