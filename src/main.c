/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

void	setup_sub(core_t *cor)
{
	for (int i = 0; i < NB_QUEST; i++)
		cor->quest[i] = 0;
	cor->ply = init_player(*cor);
	cor->obj_inv = init_obj_inventory(*cor);
	cor->obj_btl = init_obj_battle(*cor);
	cor->btl = init_battle(*cor);
	cor->obj_spell = init_obj_spell(*cor);
	init_characteristics_name(cor);
	cor->clocks = malloc(sizeof(sfClock*) * NB_CLOCKS);
	for (int i = 0; i < NB_CLOCKS; i++)
		cor->clocks[i] = sfClock_create();
	init_sound(cor);
	init_particle(cor);
}

void 	setup(core_t *cor)
{
	cor->window = my_window_create();
	cor->actual_scene = 1;
	cor->state.in_quest = 0;
	cor->state.in_menu = 0;
	cor->state.is_dead = 0;
	cor->state.in_submenu = 0;
	cor->state.change_scene = 0;
	cor->obj = get_struct_from_xml();
	cor->view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
	sfRenderWindow_setView(cor->window, cor->view);
	get_map(cor, "config/home-room.map");
	cor->button = parser_btn("config/laod_button.btn", cor);
	change_save_sprite(cor);
	setup_sub(cor);
}

int	main(void)
{
	core_t	cor;
	obj_t	**obj = parse_map_tileset("img/tile_set.png", 15, 20);

	coromp_files_test();
	srand(time(NULL));
	cor.inv = init_int_tab(NB_INVENTORY_CASE);
	cor.armor = init_armor(cor);
	cor.item = parse_item();
	setup(&cor);
	cor.text_box = NULL;
	cor.loot = NULL;
	while (sfRenderWindow_isOpen(cor.window) && my_exit(0) == 0) {
		generate_mouse_coords(&cor);
		scene_handling(&cor, obj);
	}
	return (0);
}
