/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** animation for scene change
*/

#include "my_rpg.h"

void 	reset_scene_change(int *step, int *opacity, core_t *cor)
{
	if (*step == 62) {
		*step = 0;
		*opacity = 0;
		cor->state.change_scene = 0;
	}
}

void	change_scene(core_t *cor, int scene, int menu)
{
	static sfRectangleShape *fade = NULL;
	static int 	step = 0;
	static int 	opacity = 0;
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[10]);
	float timer = curr_time.microseconds / 1000000.0;

	if (cor->state.change_scene == 0) {
		return;
	}
	fade = (fade == NULL) ? sfRectangleShape_create() : fade;
	sfRenderWindow_drawRectangleShape(cor->window, fade, NULL);
	if (timer < 0.005)
		return;
	sfRectangleShape_setSize(fade, (sfVector2f) {1920, 1080});
	opacity = (step < 31) ? opacity + 8 : opacity - 8;
	cor->actual_scene = (step++ == 31) ? scene : cor->actual_scene;
	cor->state.in_menu = (step == 32) ? menu : cor->state.in_menu;
	sfRectangleShape_setFillColor(fade, (sfColor){0, 0, 0, opacity});
	reset_scene_change(&step, &opacity, cor);
	sfClock_restart(cor->clocks[10]);
}

void 	next_scene_menu(int *next_scene, int *next_menu, core_t *cor)
{
	int temp;

	if ((*next_scene) != cor->actual_scene &&
	cor->state.change_scene == 0) {
		temp = cor->actual_scene;
		cor->actual_scene = (*next_scene);
		(*next_scene) = temp;
		temp = cor->state.in_menu;
		cor->state.in_menu = (*next_menu);
		(*next_menu) = temp;
		cor->state.change_scene = 1;
	}
}
