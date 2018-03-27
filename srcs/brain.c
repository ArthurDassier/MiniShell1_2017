/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** blabla
*/

#include "my.h"
#include "get_next_line.h"

int find_path(char **env)
{
	int	i = 0;

	while (env[i][0] != 'P' || env[i][1] != 'A' || env[i][2] != 'T'
	||  env[i][3] != 'H' || env[i][4] != '=')
		++i;
	return (i);
}

int test_path(char **tab, char **com)
{
	int	i = 0;
	int	j = -1;

	tab[0] = my_strcat("/", tab[0]);
	while (com[i] != NULL) {
		j = access(my_strcat(com[i], tab[0]), X_OK);
		if (j == 0)
			return (1);
		++i;
	}
	return (-1);
}

int main(int ac, char *av[], char **env)
{
	char	**tab = NULL;
	int	path = find_path(env);
	char	**com = my_path_to_wordtab(env[path], 5);

	(void) ac;
	(void) av;
	while (42) {
		my_putstr("[Darth_Shell]$> ");
		tab = my_str_to_wordtab(get_next_line(0));
		if (test_path(tab, com) == 1) {
			my_putstr("OK\n");
		}
	}
	return (0);
}
