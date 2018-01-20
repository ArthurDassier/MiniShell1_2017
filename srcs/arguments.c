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

int check_unsetenv(char *str)
{
	if (str[0] == 'u' && str[1] == 'n' && str[2] == 's' &&
		str[3] == 'e' && str[4] == 't' && str[5] == 'e' &&
		str[6] == 'n' && str[7] == 'v')
		return (0);
	return (-1);
}

int check_cd(char *str)
{
	if (str[0] == 'c' && str[1] == 'd')
		return (0);
	return (-1);
}

void check_arg(char *str, list_path *list_p, char **env)
{
	if (check_env(str) != -1) {
		print_list(list_p);
	} else if (check_setenv(str) != -1) {
		modif_env(str, list_p);
	} else if (check_unsetenv(str) != -1) {
		del_env(str, list_p);
	} else if (check_cd(str) != -1) {
		cd_arg(str, list_p, env);
	} else if (check_exit(str) != -1) {
		exit_me(str);
	} else
		wait_com(str, env, list_p);
}
