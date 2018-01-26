/*
** EPITECH PROJECT, 2017
** errors.c
** File description:
** blabla
*/

#include "my.h"

char *check_eq(char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (str[i] == '=')
			return (str);
		++i;
	}
	str[i] = '=';
	str[i + 1] = '\0';
	return (str);
}

int check_alpha_num(char *str)
{
	int	i = 7;

	if ((str[7] && str[7] >= 65 && str[7] <= 90) ||
	(str[7] >= 97 && str[8] <= 122)) {
		++i;
	} else if (str[7]) {
		my_puterror("setenv: Variable name must begin with a letter.\n");
		return (-1);
	}
	while (str[i] != '\0' && str[i]) {
		if ((str[i] >= 48 && str[i] <= 57) ||
			(str[i] >= 65 && str[i] <= 90) ||
			(str[i] >= 97 && str[i] <= 122) || str[i] == ' ') {
				++i;
		} else {
			my_puterror("setenv: Variable name must contain alphanumeric characters.\n");
			return (-1);
		}
	}
	return (0);
}

void error_handler(char *str)
{
	my_puterror(str);
	my_puterror(": Command not found.");
	my_puterror("\n");
	exit(1);
}
