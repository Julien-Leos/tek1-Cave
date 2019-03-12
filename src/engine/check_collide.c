/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** colider_tilset
*/

#include "my_rpg.h"

int	is_collide(core_t *cor, obj_t **obj, V2F pos)
{
	int x_offset = (LENGHT_WIN - (cor->map.col * 32)) / 2;
	int y_offset = (HEIGHT_WIN - (cor->map.line * 32)) / 2;
	V2F center = center_map(cor->map);
	V2I tile_pos;
	int actual_tile = 0;

	if (pos.x - x_offset < 0 || pos.y - y_offset < 0
	|| pos.y + 9 > HEIGHT_WIN - center.y
	|| pos.x + 9 > LENGHT_WIN - center.x)
		return (1);
	tile_pos = (V2I){(pos.x - x_offset) / 32, (pos.y - y_offset) / 32};
	for (int i = 0; i < cor->map.layer; i++) {
		actual_tile = cor->map.info[i][tile_pos.y][tile_pos.x];
		if (actual_tile > 0 && obj[actual_tile - 1]->hit_box == 1)
			return (1);
	}
	return (0);
}

V2I	get_pos_player(core_t *cor)
{
	int x_offset = (LENGHT_WIN - (cor->map.col * 32)) / 2;
	int y_offset = (HEIGHT_WIN - (cor->map.line * 32)) / 2;
	V2I tile_pos = {(cor->ply.pos.x - x_offset) / 32,
	(cor->ply.pos.y - y_offset) / 32};

	return (tile_pos);
}
