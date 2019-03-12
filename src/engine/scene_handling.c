/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** handling different scenes
*/

#include "my_rpg.h"

void 	scene_menu(core_t *cor, obj_t **obj)
{
	if (cor->actual_scene != 1)
		return;
	display_menu(cor);
	event_menu(cor, obj);
}

void 	scene_game(core_t *cor, obj_t **obj)
{
	if (cor->actual_scene != 2 && my_exit(0) == 0)
		return;
	analyse_game_events(cor);
	sfRenderWindow_clear(cor->window, sfBlack);
	display_game(cor, obj);
	if (((cor->state.in_menu == 3 || cor->state.in_menu == 8)
	&& (cor->text_box == NULL
	|| my_strcmp(cor->text_box->str, "*!FIGHT!*")) && cor->loot == NULL)
	&& my_exit(0) == 0) {
		display_quest(cor, cor->state.in_quest, (V2F){47, 47});
		event_map(cor);
		move_player(cor, obj, cor->ply.skin_move);
		event_mob(cor);
	}
	start_fight(-1, -1, cor);
	if (cor->state.in_menu == 3 && cor->state.change_scene == 0
	&& my_exit(0) == 0) {
		cor->text_box = text_box(cor);
		cor->loot = text_loot(cor);
	}
}

void 	scene_battle(core_t *cor, obj_t **obj)
{
	if (cor->actual_scene != 3)
		return;
	display_battle(cor);
	event_battle(cor);
	(void)obj;
}

void	scene_over(core_t *cor)
{
	if (cor->actual_scene != 4)
		return;
	event_over(cor);
	sfRenderWindow_clear(cor->window, sfBlack);
	TXT_SETSIZ(cor->obj_inv.txt, 46);
	TXT_SETSTR(cor->obj_inv.txt, "GAME OVER");
	TXT_SETPOS(cor->obj_inv.txt, (V2F){850, 500});
	RDW_DRWTXT(cor->window, cor->obj_inv.txt, NULL);
}

void	scene_handling(core_t *cor, obj_t **obj)
{
	static int 	next_scene = 1;
	static int 	next_menu = 0;

	scene_menu(cor, obj);
	next_scene_menu(&next_scene, &next_menu, cor);
	if (my_exit(0) != 0)
		return;
	scene_game(cor, obj);
	next_scene_menu(&next_scene, &next_menu, cor);
	if (my_exit(0) != 0)
		return;
	scene_battle(cor, obj);
	next_scene_menu(&next_scene, &next_menu, cor);
	scene_over(cor);
	next_scene_menu(&next_scene, &next_menu, cor);
	exec_end(cor);
	next_scene_menu(&next_scene, &next_menu, cor);
	display_buttons(cor);
	change_scene(cor, next_scene, next_menu);
	sfRenderWindow_display(cor->window);
}
