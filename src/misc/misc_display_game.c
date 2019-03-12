/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** misc functions for display_game
*/

#include "my_rpg.h"

V2F	center_map(map_t map)
{
	V2F pos;
	int lenght_map = map.col * 32;
	int height_map = map.line * 32;

	pos.x = (LENGHT_WIN - lenght_map) / 2;
	pos.y = (HEIGHT_WIN - height_map) / 2;
	return (pos);
}

void	verif_is_printable(core_t *cor, obj_t **obj, int tab[3],
V2F tab_pos[2])
{
	sfSprite *sprite;
	obj_t *this = obj[cor->map.info[tab[0]][tab[1]][tab[2]] - 1];

	if (cor->map.info[tab[0]][tab[1]][tab[2]] > 0) {
		if (this->hit_box != 2) {
			sprite = this->obj;
			sfSprite_setPosition(sprite, tab_pos[1]);
			sfRenderWindow_drawSprite(cor->window, sprite, NULL);
		}
	}
}

void	verif_is_printable_2(core_t *cor, obj_t **obj, int tab[3],
V2F tab_pos[2])
{
	sfSprite *sprite;
	obj_t *this = obj[cor->map.info[tab[0]][tab[1]][tab[2]] - 1];

	if (cor->map.info[tab[0]][tab[1]][tab[2]] > 0) {
		if (this->hit_box == 2) {
			sprite = this->obj;
			sfSprite_setPosition(sprite, tab_pos[1]);
			sfRenderWindow_drawSprite(cor->window, sprite, NULL);
		}
	}
}