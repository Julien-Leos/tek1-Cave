/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** parser_rpg
*/

#include "my_rpg.h"

void	get_line_item(item_t *item, char **tab, sfTexture *tile)
{
	int nb = 0;

	item->spt = sfSprite_create();
	sfSprite_setTexture(item->spt, tile, sfTrue);
	sfSprite_setTextureRect(item->spt,
	my_recup_item_rect(my_getnbr(tab[3])));
	item->name = copy_str(tab[1]);
	item->type = get_enum(tab[2]);
	item->des = copy_str(tab[4]);
	for (int i = 5; i < 18; i++) {
		item->chrc[nb] = my_getnbr(tab[i]);
		nb += 1;
	}
}

item_t	*parse_item(void)
{
	sfTexture *tile = sfTexture_createFromFile("img/itemset.png", NULL);
	int	fd = open("config/item.itm", O_RDONLY);
	char	*str = my_get_next_line(fd);
	char **tab = my_str_to_word_array(str, ' ');
	int	nb_line = my_getnbr(tab[1]);
	item_t *item = malloc(sizeof(item_t) * nb_line);

	for (int i = 0; i < nb_line; i += 1) {
		str = my_get_next_line(fd);
		if (!str) {
			my_exit(82);
		}
		tab = my_str_to_word_array(str, ' ');
		get_line_item(&item[i], tab, tile);
	}
	close(fd);
	return (item);
}
