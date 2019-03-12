/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** move part 2
*/

#include "my_rpg.h"

void	move_up(core_t *cor, obj_t **obj, int player_nb)
{
	sfTime time = sfClock_getElapsedTime(cor->ply.clk);
	float s_perso = time.microseconds / 1000000.0;
	int pos_x = cor->ply.pos.x;
	int pos_y = cor->ply.pos.y - cor->ply.speed;

	particle_pregeneration_move(cor);
	if (is_collide(cor, obj, (V2F){pos_x, pos_y}) == 0 &&
	is_collide(cor, obj, (V2F){pos_x + 24, pos_y}) == 0)
		cor->ply.pos.y -= cor->ply.speed;
	SPR_SETPOS(cor->ply.spt, cor->ply.pos);
	sfSprite_setTextureRect(cor->ply.spt, cor->ply.rect);
	cor->ply.rect.top = (player_nb / 4 * (48 * 4)) + (3 * 48);
	if (s_perso > 0.1) {
		cor->ply.rect.left += 48;
		if (cor->ply.rect.left >= (player_nb % 4 + 1) * (48 * 3))
			cor->ply.rect.left = (player_nb % 4) * (48 * 3);
		sfClock_restart(cor->ply.clk);
	}
}

void	move_player_mous_b(core_t *cor, obj_t **obj, int player_nb, V2F vect)
{
	if (vect.x > 0)
		move_left(cor, obj, player_nb);
	if (vect.y < 0)
		move_down(cor, obj, player_nb);
	if (vect.y > 0)
		move_up(cor, obj, player_nb);
}

void 	move_player_continue(core_t *cor, obj_t **obj, int player_nb)
{
	if (sfKeyboard_isKeyPressed(sfKeyQ))
		move_left(cor, obj, player_nb);
	if (sfKeyboard_isKeyPressed(sfKeyZ))
		move_up(cor, obj, player_nb);
	if (sfKeyboard_isKeyPressed(sfKeyS))
		move_down(cor, obj, player_nb);
}