/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** event mouse/keyboard for menu scene
*/

#include "my_rpg.h"

void	analyse_game_events_2(core_t *cor, int *status)
{
	if (cor->event.type == sfEvtClosed)
		sfRenderWindow_close(cor->window);
	if (macro_button_click(sfKeyEscape, status))
		cor->state.in_menu = (cor->state.in_menu != 5) ? 5 : 3;
	if (macro_button_click(sfKeyI, status))
		cor->state.in_menu = (cor->state.in_menu != 4) ? 4 : 3;
}

void	analyse_game_events_3(core_t *cor, int *status)
{
	if (macro_button_click(sfKeyK, status))
		cor->state.in_menu = (cor->state.in_menu != 7) ? 7 : 3;
	if (macro_button_click(sfKeyO, status)) {
		cor->state.in_menu = (cor->state.in_menu != 6) ? 6 : 3;
		SPR_SETPOS(cor->obj[17]->spr, (V2F){100, 256});
		SPR_SETSCL(cor->obj[17]->spr, (V2F){1, 1});
	}
	if (mouse_button_click(cor, 8, (V2F){450, 90}, status))
		cor->state.in_menu = 5;
	cor->ply.speed = (KEY_PRSD(sfKeyLShift)) ? 6 : 3;
}

void	analyse_game_events_4(core_t *cor, int *status)
{
	int id = cor->inv[recup_select_item_id(cor)];

	if (cor->event.type == sfEvtMouseButtonPressed) {
		SPR_SETPOS(cor->item[id].spt, (V2F){cor->pos_mouse.x,
		cor->pos_mouse.y});
		RDW_DRWSPR(cor->window, cor->item[id].spt, NULL);
	}
	if (cor->state.in_menu == 7) {
		event_change_submenu_quest_spell_menu(cor, status);
		event_change_quest_menu(cor, status);
		event_hover_quest_menu(cor);
	}
	if (cor->state.in_menu == 4)
		event_inventory(cor, status);
}

void	analyse_game_events(core_t *cor)
{
	int status = 0;

	event_mouse_menu(cor);
	if (cor->state.in_menu == 4)
		move_inventory(cor, &status);
	while (sfRenderWindow_pollEvent(cor->window, &(cor->event))) {
		analyse_game_events_2(cor, &status);
		analyse_game_events_3(cor, &status);
		analyse_game_events_4(cor, &status);
		if (cor->state.in_menu == 6)
			event_spell_menu(cor, &status);
		event_keyboard_menu(cor, &status);
		event_change_keyboard_control_main(cor, &status);
		event_change_keyboard_player_main(cor, &status);
		event_change_mouse_control_main(cor, &status);
		event_change_mouse_player_main(cor, &status);
		event_change_mouse_return(cor, &status);
		event_change_inventory_pannel(cor, &status);
	}
}
