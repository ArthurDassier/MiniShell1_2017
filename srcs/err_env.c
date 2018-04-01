/*
** EPITECH PROJECT, 2018
** err_env.c
** File description:
** Arthur
*/

#include "my.h"
#include "minishell1.h"

static int try_env_simple(list_path *my_env)
{
	print_list(my_env);
	return (0);
}

static int try_first_letter(char c)
{
	if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
		my_putstr("setenv: Variable name must"
		" begin with a letter.\n");
		return (1);
	}
	return (0);
}

static int try_setenv(char **tab, list_path *my_env)
{
	int	i = 0;

	if (try_first_letter(tab[1][0]) == 1)
		return (1);
	while (tab[1][i]) {
		if (!((tab[1][i] >= 'A' && tab[1][i] <= 'Z')
		|| (tab[1][i] >= 'a' && tab[1][i] <= 'z')
		|| (tab[1][i] >= '0' && tab[1][i] <= '9')
		|| (tab[1][i] == '_'))) {
			my_putstr("setenv: Variable name must contain"
			" alphanumeric characters.\n");
			return (1);
		}
		++i;
	}
	if (tab[2])
		return (my_setenv(tab, my_env));
	else
		return (no_tab_setenv(tab, my_env));
	return (0);
}

static int try_unsetenv(char **tab, list_path *my_env)
{
	if (!tab[1]) {
		my_putstr("unsetenv: Too few arguments.\n");
		return (1);
	} else
		del_elem_list(&my_env, tab[1]);
	return (0);
}

int try_env(char **tab, list_path *my_env)
{
	if (my_strcmp(tab[0], "env") == 0 ||
	(my_strcmp(tab[0], "setenv") == 0 && !tab[1]))
		return (try_env_simple(my_env));
	if (my_strcmp(tab[0], "setenv") == 0)
		return (0);
	if (my_strcmp(tab[0], "unsetenv") == 0)
		return (0);
	return (-1);
}
