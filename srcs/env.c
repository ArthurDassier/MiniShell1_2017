/*
** EPITECH PROJECT, 2018
** env.c
** File description:
** Arthur
*/

#include "my.h"
#include "minishell1.h"

static char *modif_list(char *str, char *arg)
{
	char	*tmp = malloc(sizeof(char) *
	(my_strlen(str) + my_strlen(arg) + 1));
	int	i = 0;
	int	j = 0;

	while (str[i] != '=') {
		tmp[i] = str[i];
		++i;
	}
	tmp[i++] = '=';
	while (arg[j] != '\0') {
		tmp[i] = arg[j];
		++i;
		++j;
	}
	tmp[i] = '\0';
	return (tmp);
}

void my_setenv(char **tab, list_path *my_env)
{
	list_path	*temp = my_env;

	if (tab[3]) {
		my_putstr("setenv: Too many arguments.\n");
		return;
	}
	while (temp != NULL) {
		if (my_strncmp(tab[1], temp->name, my_strlen(tab[1])) == 0) {
			temp->name = modif_list(temp->name, tab[2]);
			return;
		}
		temp = temp->next;
	}
	insert_end(&my_env, my_strcat(my_strcat(tab[1], "="), tab[2]));
}

void my_setpath(char *ph_nm, char *path, list_path *my_env)
{
	list_path	*temp = my_env;

	while (temp != NULL) {
		if (my_strncmp(ph_nm, temp->name, my_strlen(ph_nm)) == 0) {
			temp->name = modif_list(temp->name, path);
			return;
		}
		temp = temp->next;
	}
	insert_end(&my_env, my_strcat(my_strcat(ph_nm, "="), path));
}
