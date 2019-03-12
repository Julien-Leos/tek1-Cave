/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** particles init
*/

#include "my_rpg.h"

void 	init_particle_menu(core_t *cor)
{
	int x = 0;
	int y = 0;

	for (int i = 0; i < 30; i++) {
		x = rand() % 1000 + 800;
		y = rand() % 300 + 150;
		cor->part[i].obj = sfCircleShape_create();
		cor->part[i].opacity = 0;
		cor->part[i].dir = (V2F){x, y};
		sfCircleShape_setRadius(cor->part[i].obj, 2);
		sfCircleShape_setFillColor(cor->part[i].obj,
		(sfColor){255, 255, 255, 0});
		sfCircleShape_setPosition(cor->part[i].obj, cor->part[i].dir);
	}
}

void 	init_particle_move(core_t *cor)
{
	for (int i = 30; i < 50; i++) {
		cor->part[i].obj = sfCircleShape_create();
		cor->part[i].opacity = 255;
		cor->part[i].dir = (V2F){0, 0};
		sfCircleShape_setRadius(cor->part[i].obj, 2);
		sfCircleShape_setFillColor(cor->part[i].obj,
		(sfColor){0, 137, 255, 255});
		sfCircleShape_setPosition(cor->part[i].obj, cor->part[i].dir);
	}
}

void 	init_particle_event(core_t *cor)
{
	for (int i = 50; i < 100; i++) {
		cor->part[i].obj = sfCircleShape_create();
		cor->part[i].opacity = 160;
		cor->part[i].dir = (V2F){0, 0};
		sfCircleShape_setRadius(cor->part[i].obj, 2);
		sfCircleShape_setFillColor(cor->part[i].obj,
		(sfColor){255, 234, 91, 160});
		sfCircleShape_setPosition(cor->part[i].obj, cor->part[i].dir);
	}
}

void 	init_particle(core_t *cor)
{
	cor->part = malloc(sizeof(particle_t) * 100);

	init_particle_menu(cor);
	init_particle_move(cor);
	init_particle_event(cor);
}