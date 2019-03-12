/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** part 2 of animation characrer
*/

#include "my_rpg.h"

void	animation_acast_main_character(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->ply.clk);
	float timer = curr_time.microseconds / 1000000.0;
	static int frame = 192;

	if (cor->btl.state.anim_main != 2) {
		frame = 192;
		return;
	}
	if (timer < 0.24)
		return;
	sfSprite_setTextureRect(cor->obj[14]->spr,
	(sfIntRect){frame, 128, 64, 64});
	if (frame == 320)
		cor->btl.state.anim_main = 0;
	frame = (frame == 320) ? 192 : frame + 64;
	sfClock_restart(cor->ply.clk);
}

void	animation_hit_main_character(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->ply.clk);
	float timer = curr_time.microseconds / 1000000.0;
	static int frame = 0;

	if (cor->btl.state.anim_main != 1) {
		frame = 0;
		return;
	}
	if (timer < 0.24)
		return;
	sfSprite_setTextureRect(cor->obj[14]->spr,
	(sfIntRect){frame, 128, 64, 64});
	if (frame == 128)
		cor->btl.state.anim_main = 0;
	frame = (frame == 128) ? 0 : frame + 64;
	sfClock_restart(cor->ply.clk);
}

void 	animation_stand_main_character(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->ply.clk);
	float timer = curr_time.microseconds / 1000000.0;
	static int frame = 384;

	if (cor->btl.state.anim_main != 0) {
		frame = 384;
		return;
	}
	if (timer < 0.24)
		return;
	sfSprite_setTextureRect(cor->obj[14]->spr,
	(sfIntRect){frame, 0, 64, 64});
	frame = (frame == 512) ? 384 : frame + 64;
	sfClock_restart(cor->ply.clk);
}
