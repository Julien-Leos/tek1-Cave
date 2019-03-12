/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** event for battle scene
*/

#include "my_rpg.h"

int	id_spell_from_pos(V2F pos)
{
	return ((pos.x - 100) / 256 + 4 * ((pos.y - 256) / 256));
}

int	is_spell_selected(core_t *cor, V2F pos)
{
	for (int i = 0; i < 4; i++)
		if (cor->ply.spell[i] == id_spell_from_pos(pos))
			return (1);
	return (0);
}

int	recup_id_tab_spell(core_t *cor, int id)
{
	for (int i = 0; i < 4; i++)
		if (cor->ply.spell[i] == id)
			return (i);
	return (-1);
}

int	recup_free_tab_spell(core_t *cor)
{
	for (int i = 0; i < 4; i++)
		if (cor->ply.spell[i] == -1)
			return (i);
	return (-1);
}

int	verif_pos_select_spell_menu(V2F pos)
{
	if (pos.x < 100 || pos.x > 868 || pos.y < 256 || pos.y > 522)
		return (1);
	return (0);
}
