/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** particle on move player
*/

#include "my_rpg.h"

void 	particle_generation_move(core_t *cor, int i)
{
	V2F pos;

	if (cor->part[i].dir.x == 0 && cor->part[i].dir.y == 0) {
		if (rand() % 70 != 0)
			return;
		cor->part[i].dir.x = rand() % 7 + 1;
		cor->part[i].dir.y = cor->part[i].dir.x;
		cor->part[i].opacity = 255;
		cor->part[i].pos.x = cor->ply.pos.x + 2 + rand() % 12;
		cor->part[i].pos.y = cor->ply.pos.y + 2 + rand() % 6;
		pos = cor->part[i].pos;
		sfCircleShape_setPosition(cor->part[i].obj, pos);
	}
}

void 	particle_pregeneration_move(core_t *cor)
{
	for (int i = 30; i < 50; i++)
		particle_generation_move(cor, i);
}


void 	particle_animate_move(core_t *cor, int i)
{
	int opacity = cor->part[i].opacity;
	sfColor color = (sfColor){121, 179, 229, opacity};
	V2F pos = cor->part[i].pos;

	if (cor->part[i].dir.y > 0) {
		cor->part[i].dir.y -= 1;
		cor->part[i].pos.y -= 1;
		cor->part[i].opacity -= 15;
		sfCircleShape_setFillColor(cor->part[i].obj, color);
		sfCircleShape_setPosition(cor->part[i].obj, pos);
		return;
	}
	if (cor->part[i].dir.x > 0) {
		cor->part[i].dir.x -= 1;
		cor->part[i].pos.y += 1;
		cor->part[i].opacity -= 15;
		sfCircleShape_setFillColor(cor->part[i].obj, color);
		sfCircleShape_setPosition(cor->part[i].obj, pos);
	}
}

void 	particle_draw_move(core_t *cor, int y)
{
	for (int i = 30; i < 50; i++) {
		if (cor->part[i].dir.x == 0 && cor->part[i].dir.y == 0)
			continue;
		if (y == cor->part[i].pos.y) {
			sfRenderWindow_drawCircleShape(cor->window,
			cor->part[i].obj, NULL);
		}
	}
}

void 	particle_move(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[21]);
	float timer = curr_time.microseconds / 1000000.0;

	for (int i = 30; i < 50; i++) {
		if (timer > 0.02) {
			particle_animate_move(cor, i);
			sfClock_restart(cor->clocks[21]);
		}
	}
}