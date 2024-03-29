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

int error_status(int wstatus)
{
	int	ret = wstatus / 256;

	(void) ret;
	if (WIFSIGNALED(wstatus)) {
		if (WTERMSIG(wstatus) == 11) {
			my_puterror("Segmentation fault\n");
			return (139);
		} else if (WTERMSIG(wstatus) == 8) {
			my_puterror("Floating exception\n");
			return (136);
		}
	}
	return (0);
}

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
	int	wstatus;

	if (tab != NULL)
		++tab[0];
	child_pid = fork();
	if (child_pid == 0) {
		execve(order, tab, new_env);
	} else
		if (wait(&wstatus) != -1)
			return (error_status(wstatus));
	return (0);
}

int test_path(char **tab, char **com, char **new_env)
{
	int	i = 0;
	int	j = -1;

	tab[0] = my_strcat("/", tab[0]);
	while (com[i] != NULL) {
		if (i == 0 && com[5])
			com[i] += 5;
		j = access(my_strcat(com[i], tab[0]), F_OK || X_OK);
		if (j == 0)
			return (exec(my_strcat(com[i], tab[0]), tab, new_env));
		++i;
	}
	if (access(++tab[0], F_OK || X_OK) == 0)
		return (exec(tab[0], tab, new_env));
	my_putstr(tab[0]);
	my_putstr(": Command not found.\n");
	return (1);
}
