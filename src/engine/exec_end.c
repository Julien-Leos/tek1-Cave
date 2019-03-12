/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** colider_tilset
*/

#include "my_rpg.h"

void	exec_end(core_t *cor)
{
	if (cor->actual_scene != 42)
		return;
	event_over(cor);
	SPR_SETSCL(cor->obj[87]->spr, (V2F){1.5, 1.5});
	SPR_SETPOS(cor->obj[87]->spr, (V2F){50, 0});
	RDW_DRWSPR(cor->window, cor->obj[87]->spr, NULL);
}