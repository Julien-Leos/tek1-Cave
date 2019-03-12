/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** particle on menu
*/

#include "my_rpg.h"

void 	particle_generation_menu(core_t *cor, int i)
{
	if (cor->part[i].opacity == 0) {
		if (rand() % 100 != 0)
			return;
		cor->part[i].opacity = 255;
	}
}

void 	particle_animate_menu(core_t *cor, int i)
{
	int opacity = cor->part[i].opacity;

	if (cor->part[i].opacity > 0) {
		cor->part[i].opacity -= 5;
		sfCircleShape_setFillColor(cor->part[i].obj,
		(sfColor){255, 255, 255, opacity});
	}
}

void 	particle_draw_event(core_t *cor, int y)
{
	for (int i = 50; i < 100; i++) {
		if (cor->part[i].opacity == 0)
			continue;
		if (y == cor->part[i].pos.y) {
			sfRenderWindow_drawCircleShape(cor->window,
			cor->part[i].obj, NULL);
		}
	}
}

void 	particle_menu(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[21]);
	float timer = curr_time.microseconds / 1000000.0;

	for (int i = 0; i < 30; i++) {
		particle_generation_menu(cor, i);
		if (timer > 0.01) {
			particle_animate_menu(cor, i);
			sfClock_restart(cor->clocks[21]);
		}
		if (cor->part[i].opacity > 0) {
			sfRenderWindow_drawCircleShape(cor->window,
			cor->part[i].obj, NULL);
		}
	}
}