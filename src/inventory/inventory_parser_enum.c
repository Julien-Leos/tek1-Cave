/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** parser_rpg
*/

#include "my_rpg.h"

int	get_enum_end(char *str)
{
	if (my_strcmp(str, "ITEM"))
		return (ITEM);
	else if (my_strcmp(str, "EMPTY"))
		return (EMPTY);
	else {
		my_exit(72);
		return (0);
	}
}

int	get_enum_4(char *str)
{
	if (my_strcmp(str, "QUEST"))
		return (QUEST);
	else
		return (get_enum_end(str));
}

int	get_enum_3(char *str)
{
	if (my_strcmp(str, "DICE"))
		return (DICE);
	else if (my_strcmp(str, "POTION"))
		return (POTION);
	else
		return (get_enum_4(str));
}

int	get_enum_2(char *str)
{
	if (my_strcmp(str, "BOOTS"))
		return (BOOTS);
	else if (my_strcmp(str, "GLOVES"))
		return (GLOVES);
	else
		return (get_enum_3(str));
}

int	get_enum(char *str)
{
	if (my_strcmp(str, "HELMET"))
		return (HELMET);
	else if (my_strcmp(str, "CHESTPLATE"))
		return (CHESTPLATE);
	else
		return (get_enum_2(str));
	return (0);
}
