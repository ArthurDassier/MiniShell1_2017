/*
** EPITECH PROJECT, 2017
** environement.c
** File description:
** blabla
*/

#include "my.h"

int check_existing(char *checking, char *str)
{
	int	i = 0;
	int	j = 6;

	while (checking[i] != '=') {
		if (checking[i] != str[j])
			return (0);
		++i;
		++j;
	}
	++i;
	while (str[j] != '\0') {
		checking[i] = str[j];
		++i;
		++j;
	}
	checking[i] = '\0';
	return (1);
}

void check_envvar(char *str, list_path *list_p)
{
	list_path	*temp;
	int		i = 0;

	temp = list_p;
	while (temp != NULL && i == 0) {
		i = check_existing(temp->path_name, str);
		temp = temp->next;
	}
	if (i == 0) {
		insert_end(&list_p, str);
		printf("--%s--\n", str);
	}
}

void modif_env(char *str, list_path *list_p)
{
	if (str[6] == '\0')
		print_list(list_p);
	if (str[6] == ' ')
		check_envvar(str, list_p);
}
