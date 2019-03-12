/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** event for battle scene
*/

#include "my_rpg.h"

void	event_spell_menu_mouse(core_t *cor, V2I pos1, V2F pos2)
{
	int free_id = recup_free_tab_spell(cor);
	int actual_id = recup_id_tab_spell(cor, id_spell_from_pos(pos2));

	if (0 <= pos1.x && pos1.x <= 3 && 1 <= pos1.y && pos1.y <= 2) {
		if (sfMouse_isButtonPressed(sfMouseLeft))
			SPR_SETPOS(cor->obj[17]->spr, pos2);
		if (sfMouse_isButtonPressed(sfMouseLeft) &&
		is_spell_selected(cor, pos2) == 0 &&
		cor->obj_spell.nbr_spell < 4) {
			cor->ply.spell[free_id] = id_spell_from_pos(pos2);
			cor->obj_spell.nbr_spell++;
		}
		if (sfMouse_isButtonPressed(sfMouseLeft) &&
		is_spell_selected(cor, pos2) == 1) {
			cor->ply.spell[actual_id] = -1;
			cor->obj_spell.nbr_spell--;
		}
	}
}

void	event_spell_menu_return(core_t *cor, int *status, V2F select)
{
	int status_tmp = macro_button_click(sfKeyReturn, status);
	int free_id = recup_free_tab_spell(cor);
	int actual_id = recup_id_tab_spell(cor, id_spell_from_pos(select));

	if (status_tmp && is_spell_selected(cor, select) == 0 &&
	cor->obj_spell.nbr_spell < 4) {
		cor->ply.spell[free_id] = id_spell_from_pos(select);
		cor->obj_spell.nbr_spell++;
	}
	if (status_tmp && is_spell_selected(cor, select) == 1) {
		cor->ply.spell[actual_id] = -1;
		cor->obj_spell.nbr_spell--;
	}
}

void	event_spell_menu_arrow_1(core_t *cor, int *status, V2F select)
{
	if (macro_button_click(sfKeyUp, status) &&
	verif_pos_select_spell_menu((V2F){select.x, select.y - 256}) == 0) {
		SPR_SETPOS(cor->obj[17]->spr, (V2F){select.x, select.y - 256});
	}
	if (macro_button_click(sfKeyDown, status) &&
	verif_pos_select_spell_menu((V2F){select.x, select.y + 256}) == 0) {
		SPR_SETPOS(cor->obj[17]->spr, (V2F){select.x, select.y + 256});
	}
}

void	event_spell_menu_arrow_2(core_t *cor, int *status, V2F select)
{
	if (macro_button_click(sfKeyLeft, status) &&
	verif_pos_select_spell_menu((V2F){select.x - 256, select.y}) == 0) {
		SPR_SETPOS(cor->obj[17]->spr, (V2F){select.x - 256, select.y});
	}
	if (macro_button_click(sfKeyRight, status) &&
	verif_pos_select_spell_menu((V2F){select.x + 256, select.y}) == 0) {
		SPR_SETPOS(cor->obj[17]->spr, (V2F){select.x + 256, select.y});
	}
}

void	event_spell_menu(core_t *cor, int *status)
{
	V2I pos1 = {(cor->pos_mouse.x - 100) / 256, (cor->pos_mouse.y) / 256};
	V2F pos2 = {pos1.x * 256 + 100, pos1.y * 256};
	V2F select = SPR_GETPOS(cor->obj[17]->spr);

	event_spell_menu_mouse(cor, pos1, pos2);
	event_spell_menu_return(cor, status, select);
	event_spell_menu_arrow_1(cor, status, select);
	event_spell_menu_arrow_2(cor, status, select);
}
