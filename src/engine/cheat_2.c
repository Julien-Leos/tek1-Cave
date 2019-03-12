/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** comp_char_files
*/

#include "my_rpg.h"

int	coromp_files_test_5(int nb)
{
	char *test[] = {"config/collide_tileset", "config/farm2-bottom.map",
	"config/farm2-bottom.map.event", "config/farm2-bottom.map.mob",
	"config/farm2-top.map", "config/farm2-top.map.event",
	"config/farm2-top.map.mob", "config/farm3-farm4.map",
	"config/farm3-farm4.map.event", "config/farm3-farm4.map.mob",
	"config/farm3-main.map", "config/farm3-main.map.event",
	"config/farm3-main.map.mob", "config/farm4-main.map",
	"config/farm4-main.map.event", "config/farm4-main.map.mob",
	"config/farm_map_1.map", "config/farm_map_1.map.event",
	"config/farm_map_1.map.mob", "config/farm_map_2.map",
	"config/farm_map_2.map.event", "config/farm_map_2.map.mob", NULL};

	for (int i = 0; test[i] != NULL; i++)
		nb += comp_char_files(test[i]);
	return (nb);
}

int	coromp_files_test_4(int nb)
{
	char *test[] = {"config/final-cave.map",
	"config/final-cave.map.event",
	"config/final-cave.map.mob", "config/home-main.map",
	"config/home-main.map.event", "config/home-main.map.mob",
	"config/home-room.map", "config/home-room.map.event",
	"config/home-room.map.mob", "config/item.itm",
	"config/laboratory-cave.map", "config/laboratory-cave.map.event",
	"config/laboratory-cave.map.mob", "config/laboratory-main.map",
	"config/laboratory-main.map.event", "config/laboratory-main.map.mob",
	"config/laod_button.btn", "config/library-house.map",
	"config/library-house.map.event", "config/library-house.map.mob",
	"config/library-main.map", "config/library-main.map.event",
	"config/library-main.map.mob", "config/library-path.map",
	"config/library-path.map.event", "config/library-path.map.mob",
	"config/market-house-left.map", "config/market-house-left.map.event",
	NULL};

	for (int i = 0; test[i] != NULL; i++)
		nb += comp_char_files(test[i]);
	return (coromp_files_test_5(nb));
}

int	coromp_files_test_3(int nb)
{
	char *test[] = {"config/market-house-left.map.mob",
	"config/market-house-top.map",
	"config/market-house-top.map.event", "config/market-house-top.map.mob",
	"config/market-main.map", "config/market-main.map.event",
	"config/market-main.map.mob", "config/ode-main-left.map",
	"config/ode-main-left.map.event", "config/ode-main-left.map.mob",
	"config/ode-main.map", "config/ode-main.map.event",
	"config/ode-main.map.mob", "config/ode-main-right.map",
	"config/ode-main-right.map.event", "config/ode-main-right.map.mob",
	"config/ode-path-house-bottom.map",
	"config/ode-path-house-bottom.map.event",
	"config/ode-path-house-bottom.map.mob",
	"config/ode-path-house-left.map",
	"config/ode-path-house-left.map.event",
	"config/ode-path-house-left.map.mob", "config/ode-path-house-top.map",
	NULL};

	for (int i = 0; test[i] != NULL; i++)
		nb += comp_char_files(test[i]);
	return (coromp_files_test_4(nb));
}