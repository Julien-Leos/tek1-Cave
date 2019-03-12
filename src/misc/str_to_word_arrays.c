/*
** EPITECH PROJECT, 2017
** Boostrap
** File description:
** Boostrap
*/

#include "my_rpg.h"

int countword(char *str, char c)
{
	int count = 0;

	for (int i = 0;  str && str[i] && str[i] != '\0'; i++) {
		if (str[i] == c)
			count += 1;
	}
	return (count + 1);
}

int get_strlen_word(char *str, char c)
{
	int i = 0;

	for (i = 0; str && str[i] && str[i] != c; i++);
	return (i);
}

char *getword(char *str_array, char *str, char c)
{
	int i;

	for (i = 0;  str && str[i] && str[i] != c; i++) {
		str_array[i] = str[i];
	}
	str_array[i] = 0;
	return (str_array);
}

char **my_str_to_word_array(char *str, char c)
{
	int nb = 0;
	int word = 0;
	char **str_array;

	str_array = malloc(sizeof(char*) * (countword(str, c) + 1));
	if (str_array == NULL)
		return (NULL);
	for (nb = 0; nb != countword(str, c); nb++) {
		str_array[nb] = malloc(sizeof(char)
		* get_strlen_word(str + word, c) + 1);
		str_array[nb] = getword(str_array[nb], str + word, c);
		word += get_strlen_word(str + word, c) + 1;
	}
	str_array[nb] = NULL;
	return (str_array);
}
