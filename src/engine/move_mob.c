/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** move mobs on the map with collisions
*/

#include "my_rpg.h"

void 	generate_mob_dir(core_t *cor, int i)
{
	if (cor->mob[i].dir.x == 0 && cor->mob[i].dir.y == 0) {
		if (rand() % 75 != 0 || cor->mob[i].is_static == 1)
			return;
		cor->mob[i].dir.x = rand() % 30;
		cor->mob[i].dir.x *= (rand() % 2 == 0) ? -1 : 1;
		cor->mob[i].dir.y = rand() % 30;
		cor->mob[i].dir.y *= (rand() % 2 == 0) ? -1 : 1;
	}
}

void 	which_move_mob_last(core_t *cor, obj_t **obj, int i, float s_perso)
{
	if (cor->mob[i].dir.y < 0) {
		move_mob_down(cor, obj, i, s_perso);
		cor->mob[i].dir.y += 1;
	}
}

void 	which_move_mob(core_t *cor, obj_t **obj, int i, float s_perso)
{
	if (cor->mob[i].dir.x > 0) {
		move_mob_right(cor, obj, i, s_perso);
		cor->mob[i].dir.x -= 1;
		return;
	}
	if (cor->mob[i].dir.x < 0) {
		move_mob_left(cor, obj, i, s_perso);
		cor->mob[i].dir.x += 1;
		return;
	}
	if (cor->mob[i].dir.y > 0) {
		move_mob_up(cor, obj, i, s_perso);
		cor->mob[i].dir.y -= 1;
		return;
	}
	which_move_mob_last(cor, obj, i, s_perso);
}

void 	move_mob(core_t *cor, obj_t **obj)
{
	sfTime time = sfClock_getElapsedTime(cor->clocks[11]);
	float s_perso = time.microseconds / 1000000.0;

	for (int i = 0; i < cor->state.nb_ennemy; i++) {
		if (cor->state.in_menu == 3) {
			generate_mob_dir(cor, i);
			which_move_mob(cor, obj, i, s_perso);
		}
		SPR_SETPOS(cor->mob[i].spr, cor->mob[i].pos);
	}
	if (s_perso > 0.1)
		sfClock_restart(cor->clocks[11]);
}