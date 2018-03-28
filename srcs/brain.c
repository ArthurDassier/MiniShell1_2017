/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** blabla
*/

#include "my.h"
#include "get_next_line.h"
#include "minishell1.h"
#include <sys/types.h>
#include <sys/wait.h>

char *find_path(list_path *my_env)
{
	list_path	*tmp = my_env;

	while (my_strncmp(tmp->name, "PATH=", 4) != 0)
		tmp = tmp->next;
	return (tmp->name);
}

int exec(char *order, char **tab, char **env)
{
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid == 0)
		execve(order, tab, env);
	else
		wait(NULL);
	return (0);
}

int test_path(char **tab, char **com)
{
	int	i = 0;
	int	j = -1;

	tab[0] = my_strcat("/", tab[0]);
	while (com[i] != NULL) {
		j = access(my_strcat(com[i], tab[0]), F_OK || X_OK);
		if (j == 0)
			return (exec(my_strcat(com[i], tab[0]), tab, NULL));
		++i;
	}
	return (-1);
}

int shell(list_path *my_env)
{
	char	**tab;
	char	*path = find_path(my_env);
	char	**com = my_path_to_wordtab(path, 5);

	while (42) {
		my_putstr("[Darth_Shell]$> ");
		tab = my_str_to_wordtab(get_next_line(0));
		if (test_path(tab, com) == -1)
			my_putstr("wtf is that command\n");
	}
}

int main(int ac, char *av[], char **env)
{
	list_path	*my_env = init_cl(env);
	int		i = 1;

	if (my_env == NULL)
		return (84);
	while (env[i]) {
		insert_end(&my_env, env[i]);
		++i;
	}
	if (shell(my_env) == 84)
		return (84);
	return (0);
}
