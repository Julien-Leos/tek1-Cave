/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** lib func part 2
*/

#include "my_rpg.h"

char	*str_fill(char *str, int nbr, int tmp, int length)
{
	int i = 0;

	while (i != length) {
		str[i++] = (nbr / tmp) % 10 + '0';
		tmp /= 10;
	}
	str[i] = '\0';
	return (str);
}

int	nbr_length_getchar(int nbr, int *tmp)
{
	int	length = 0;

	while (nbr / *tmp > 0) {
		*tmp *= 10;
		length++;
	}
	return (length);
}

int	my_strcmp(char *str, char *str2)
{
	int nb = 0;

	for (; str[nb] != '\0'; nb += 1) {
		if (str2[nb] == '\0')
			break;
		if (str[nb] != str2[nb])
			return (0);
	}
	if (str2[nb] != '\0')
		return (0);
	return (1);
}

char	*my_getchar(int nbr)
{
	char	*str;
	int	tmp = 1;
	int	length = 0;

	str = malloc(sizeof(char) * 10);
	if (!str)
		return (NULL);
	if (nbr == 0)
		return ("0");
	length = nbr_length_getchar(nbr, &tmp);
	tmp /= 10;
	str = str_fill(str, nbr, tmp, length);
	return (str);
}

char	*concat(char *str1, char *str2)
{
	int	size_str1 = my_strlen(str1);
	int	size_str2 = my_strlen(str2);
	int	nb = 0;
	char	*final = malloc(sizeof(char) * (size_str1 + size_str2 + 1));

	for (int i = 0; i < (size_str1 + size_str2 + 1); i += 1);
	for (int i = 0; str1[i] != '\0'; i += 1, nb += 1)
		final[nb] = str1[i];
	for (int i = 0; str2[i] != '\0'; i += 1, nb += 1)
		final[nb] = str2[i];
	final[nb] = '\0';
	return (final);
}