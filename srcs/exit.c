/*
** EPITECH PROJECT, 2017
** exit.c
** File description:
** blabla
*/

#include "my.h"

int check_exit(char *str)
{
	if (str[0] == 'e' && str[1] == 'x' && str[2] == 'i' && str[3] == 't')
		return (0);
	return (-1);
}

void exit_me(char *str)
{
	char	*tmp = malloc(sizeof(char) * 1024);
	int	i = 6;
	int	j = 0;

	if (my_strlen(str) == 4)
		exit(0);
	else {
		while (str[i] != '\0') {
			tmp[j] = str[i];
			++i;
			++j;
		}
		tmp[j] = '\0';
		exit(my_getnbr(tmp));
	}
}
