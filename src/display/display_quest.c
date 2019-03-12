/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** quest menu display
*/

#include "my_rpg.h"

sfRectangleShape *setup_actual_rect_s(sfRectangleShape *actual)
{
	actual = RCT_CREATE();
	RCT_SETPOS(actual, (V2F){106, 192});
	RCT_SETSIZ(actual, (V2F){1706, 149});
	RCT_SETCLR(actual, sfColor_fromRGBA(200, 200, 200, 35));
	return (actual);
}

void 	quest_actual_selection(core_t *cor, sfRectangleShape *actual)
{
	V2F 	pos = (V2F){106, 192};

	pos.y = (cor->state.in_submenu == 8) ? 192 : pos.y;
	pos.y = (cor->state.in_submenu == 9) ? 366 : pos.y;
	pos.y = (cor->state.in_submenu == 10) ? 540 : pos.y;
	pos.y = (cor->state.in_submenu == 11) ? 716 : pos.y;
	RCT_SETPOS(actual, pos);
}

void 	quest_star_selection(core_t *cor)
{
	V2F 	pos = (V2F){115, 201};

	pos.y = (cor->state.in_quest == 0) ? 201 : pos.y;
	pos.y = (cor->state.in_quest == 1) ? 375 : pos.y;
	pos.y = (cor->state.in_quest == 2) ? 549 : pos.y;
	pos.y = (cor->state.in_quest == 3) ? 725 : pos.y;
	SPR_SETPOS(cor->obj[34]->spr, pos);
}

void	display_quest(core_t *cor, int i, V2F pos)
{
	int fd = open("quest/0.qst", O_RDONLY);
	char *str = "NULL";
	int j = (cor->state.in_menu != 3) ? 0 : 1;

	for (int nb = 0; nb <= cor->quest[i] && str; nb += 1)
		str = my_get_next_line(fd);
	if (str)
		draw_text(str, cor, pos, j);
	else
		draw_text("NULL", cor, pos, j);
	close(fd);
}

void 	display_quest_menu(core_t *cor)
{
	static sfRectangleShape *actual = NULL;

	if (cor->state.in_submenu < 8 || cor->state.in_submenu > 11)
		cor->state.in_submenu = 8;
	actual = (actual == NULL) ? setup_actual_rect_s(actual) : actual;
	quest_actual_selection(cor, actual);
	quest_star_selection(cor);
	sfRenderWindow_drawSprite(cor->window, cor->obj[33]->spr, NULL);
	sfSprite_setScale(cor->obj[34]->spr, (V2F){1, 1});
	sfRenderWindow_drawSprite(cor->window, cor->obj[34]->spr, NULL);
	sfRenderWindow_drawRectangleShape(cor->window, actual, NULL);
	display_quest(cor, 0, (V2F){300, 200});
}