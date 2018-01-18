/*
** EPITECH PROJECT, 2017
** arguments.c
** File description:
** blabla
*/

#include "my.h"

int check_env(char *str)
{
	if (my_strlen(str) == 3 &&
	str[0] == 'e' && str[1] == 'n' && str[2] == 'v')
		return (0);
	return (-1);
}

int check_setenv(char *str)
{
	if (str[0] == 's' && str[1] == 'e' && str[2] == 't' &&
	str[3] == 'e' && str[4] == 'n' && str[5] == 'v')
		return (0);
	return (-1);
}

void check_arg(char *str, list_path *list_p, char **env)
{
	if (check_env(str) != -1) {
		print_list(list_p);
	} else if (check_setenv(str) != -1) {
		modif_env(str, list_p);
	} else
		wait_com(str, env, list_p);
}
