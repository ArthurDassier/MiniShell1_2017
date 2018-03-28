/*
** EPITECH PROJECT, 2018
** simple_com.c
** File description:
** Arthur
*/

#include "my.h"
#include "get_next_line.h"
#include "minishell1.h"
#include "printf.h"
#include <sys/types.h>
#include <sys/wait.h>

char *find_path(list_path *my_env)
{
	list_path	*tmp = my_env;

	while (tmp != NULL && my_strncmp(tmp->name, "PATH=", 4) != 0)
		tmp = tmp->next;
	if (tmp == NULL)
		return ("\0");
	return (tmp->name);
}

static int exec(char *order, char **tab, char **new_env)
{
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid == 0) {
		execve(order, tab, new_env);
	} else
		wait(NULL);
	return (0);
}

int test_path(char **tab, char **com, char **new_env)
{
	int	i = 0;
	int	j = -1;
	tab[0] = my_strcat("/", tab[0]);
	while (com[i] != NULL) {
		j = access(my_strcat(com[i], tab[0]), F_OK || X_OK);
		if (j == 0)
			return (exec(my_strcat(com[i], tab[0]), tab, new_env));
		++i;
	}
	my_printf("%s: Command not found.\n", ++tab[0]);
	return (-1);
}
