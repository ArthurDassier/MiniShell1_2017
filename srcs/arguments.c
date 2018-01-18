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
		return(0);
	return (-1);
}

void check_arg(char *str, list_path *list_p, char **env)
{
	if (check_env(str) != -1) {
		print_list(list_p);
		exit(0);
	} else
		bin_tests(str, list_p, env);
}
