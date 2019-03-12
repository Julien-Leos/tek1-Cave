/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** lib_fonc
*/

#include "my_rpg.h"

int	my_getnbr(char *str)
{
	int final = 0;
	int moins = 1;
	int i = 0;

	if (str[i] == '-' && !(str == NULL)) {
		moins = -1;
		i += 1;
	}
	for (; str[i] != '\0' && !(str == NULL); i += 1) {
		if (str[i] >= '0' && str[i] <= '9')
			final = final * 10 + str[i] - '0';
		else {
			my_exit(84);
			return (0);
		}
	}
	final = final * moins;
	return (final);
}

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	my_putstr(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		my_putchar(str[i]);
}

float	my_getfloat(char *str)
{
	int i = 0;
	int integer = 0;
	float decimal = 0;
	int is_negative = 1;

	if (str == NULL)
		return (-1);
	if (str[i] == '-') {
		is_negative = -1;
		i++;
	}
	for (; str[i] != '.'; i++)
		integer = (integer * 10) + str[i] - '0';
	i++;
	for (; str[i] != '\0'; i++)
		decimal = (decimal * 10) + str[i] - '0';
	return ((integer + (decimal / 100)) * is_negative);
}

int	my_strlen(const char *str)
{
	int nb = 0;

	for (; str[nb] != '\0'; nb += 1);
	return (nb);
}