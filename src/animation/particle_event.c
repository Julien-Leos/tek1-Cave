/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** particle event
*/

#include "my_rpg.h"

int 	particle_generation_event(core_t *cor, int i, V2F pos)
{

	if (cor->part[i].opacity == 0) {
		if (rand() % 2500 != 0)
			return (0);
		cor->part[i].opacity = 200 - (rand() % 3) * 20;
		pos.y += rand() % 32 - 16;
		pos.x += rand() % 28;
		cor->part[i].pos.y = pos.y;
		sfCircleShape_setPosition(cor->part[i].obj, pos);
	}
	return (1);
}

void 	particle_pregeneration_event(core_t *cor, int i, int j)
{
	int 	max_gen = 0;
	V2F	pos;
	V2F 	center;

	if (cor->map.event[j][i] == 0)
		return;
	center = center_map(cor->map);
	pos = (V2F){center.x + i * 32, center.y + j * 32};
	for (int k = 50; k < 100 && max_gen < 3; k++) {
		if (particle_generation_event(cor, k, pos))
			max_gen += 1;
	}
}

void 	particle_search_event(core_t *cor)
{
	for (int i = 0; i < cor->map.col; i++)
		for (int j = 0; j < cor->map.line; j++)
			particle_pregeneration_event(cor, i, j);
}


void 	particle_animate_event(core_t *cor, int i)
{
	int opacity = cor->part[i].opacity;

	if (cor->part[i].opacity > 0) {
		cor->part[i].opacity -= 20;
		sfCircleShape_setFillColor(cor->part[i].obj,
		(sfColor){255, 234, 91, opacity});
	}
}

void 	particle_event(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[22]);
	float timer = curr_time.microseconds / 1000000.0;

	for (int i = 50; i < 100; i++) {
		if (timer > 0.015)
			particle_search_event(cor);
		if (timer > 0.03) {
			particle_animate_event(cor, i);
			sfClock_restart(cor->clocks[22]);
		}
	}
}