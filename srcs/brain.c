/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** blabla
*/

#include "my.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/wait.h>

int find_path(char **env)
{
	int	i = 0;

	while (env[i][0] != 'P' || env[i][1] != 'A' || env[i][2] != 'T'
	||  env[i][3] != 'H' || env[i][4] != '=')
		++i;
	return (i);
}

int execution(char *order, char **tab, char **env)
{
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid == 0)
		execve(order, tab, env);
	else
		wait(NULL);
	return (0);
}

int test_path(char **tab, char **com, char **env)
{
	int	i = 0;
	int	j = -1;

	tab[0] = my_strcat("/", tab[0]);
	while (com[i] != NULL) {
		j = access(my_strcat(com[i], tab[0]), F_OK || X_OK);
		if (j == 0)
			return (execution(my_strcat(com[i], tab[0]), tab, env));
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
		if (test_path(tab, com, env) == -1)
			my_putstr("wtf is that command\n");
	}
	return (0);
}
