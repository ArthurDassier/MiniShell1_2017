/*
** EPITECH PROJECT, 2017
** environement.c
** File description:
** blabla
*/

#include "my.h"

char *my_set(char *str)
{
	int	i = 0;
	int	j = 0;
	char	*tmp = malloc(100);

	while (str[i] != ' ') {
		++i;
	}
	++i;
	while (str[i] != '\0') {
		tmp[j] = str[i];
		if (tmp[j] == ' ')
			tmp[j] = '=';
		++j;
		++i;
	}
	return (tmp);
}

int check_existing(char *checking, char *str)
{
	int	i = 0;
	int	j = 7;

	while (checking[i] != '=' || str[j] != ' ') {
		if (checking[i] != str[j])
			return (0);
		++i;
		++j;
	}
	++i;
	++j;
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
		str = my_set(str);
		insert_end(&list_p, str);
		print_list(list_p);
	}
}

void modif_env(char *str, list_path *list_p)
{
	if (str[6])
		check_envvar(str, list_p);
	else
		print_list(list_p);
}
