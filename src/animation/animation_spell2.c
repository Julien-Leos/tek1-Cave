/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** part 2 of animation spell
*/

#include "my_rpg.h"

void 	animation_meteor_spell(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[0]);
	float timer = curr_time.microseconds / 1000000.0;
	static int x = 0;
	static int y = 0;

	if (cor->btl.state.anim_spell != 1) {
		x = 0;
		y = 0;
		return;
	}
	RDW_DRWSPR(cor->window, cor->obj[24]->spr, NULL);
	if (timer < 0.03)
		return;
	sfSprite_setTextureRect(cor->obj[24]->spr,
	(sfIntRect){x, y, 128, 128});
	if (x >= 512 && y >= 512)
		cor->btl.state.anim_spell = 0;
	y += (x == 512) ? 128 : 0;
	x = (x == 512) ? 0 : x + 128;
	sfClock_restart(cor->clocks[0]);
}

void 	animation_bramble_continue(int *status, int *x, int *y)
{
	if (*status == 0) {
		*y += (*x == 512) ? 128 : 0;
		*x = (*x == 512) ? 0 : *x + 128;
	}
	if (*status == 1) {
		*y -= (*x == 0) ? 128 : 0;
		*x = (*x == 0) ? 512 : *x - 128;
	}
	if (*x == 512 && *y == 512 && *status == 0)
		*status = 1;
}

void 	animation_bramble_spell(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[1]);
	float timer = curr_time.microseconds / 1000000.0;
	static int x = 0;
	static int y = 0;
	static int status = 0;

	if (cor->btl.state.anim_spell != 2) {
		x = 0;
		y = 0;
		status = 0;
		return;
	}
	RDW_DRWSPR(cor->window, cor->obj[25]->spr, NULL);
	if (timer < 0.01)
		return;
	sfSprite_setTextureRect(cor->obj[25]->spr, (INTRCT){x, y, 128, 128});
	if (x <= 0 && y <= 0 && status == 1)
		cor->btl.state.anim_spell = 0;
	animation_bramble_continue(&status, &x, &y);
	sfClock_restart(cor->clocks[1]);
}

void animation_special_continue(core_t *cor, int *status, int *x, int *y)
{
	if (*status == 0) {
		*y += (*x == 512) ? 128 : 0;
		*x = (*x == 512) ? 0 : *x + 128;
	}
	if (*status == 1) {
		*y -= (*x == 0) ? 128 : 0;
		*x = (*x == 0) ? 512 : *x - 128;
	}
	if (*x == 512 && *y == 384 && *status == 0)
		*status = 1;
	sfClock_restart(cor->clocks[6]);
}

void 	animation_special_spell(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[6]);
	float timer = curr_time.microseconds / 1000000.0;
	static int x = 0;
	static int y = 0;
	static int status = 0;

	if (cor->btl.state.anim_spell != 7) {
		x = 0;
		y = 0;
		status = 0;
		return;
	}
	RDW_DRWSPR(cor->window, cor->obj[30]->spr, NULL);
	if (timer < 0.03)
		return;
	sfSprite_setTextureRect(cor->obj[30]->spr,
	(sfIntRect){x, y, 128, 128});
	if (x <= 0 && y <= 0 && status == 1)
		cor->btl.state.anim_spell = 0;
	animation_special_continue(cor, &status, &x, &y);
}
