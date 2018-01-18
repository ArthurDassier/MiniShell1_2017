/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** blabla
*/

#include "my.h"

int get_path(char **env)
{
	for (int i = 0; env[i]; ++i) {
		if (env[i][0] == 'P' && env[i][1] == 'A' &&
		env[i][2] == 'T' && env[i][3] == 'H' && env[i][4] == '=')
			return (i);
	}
	return (-1);
}

list_path *init_chain_path(char **env)
{
	list_path	*element = malloc(sizeof(list_path));

	element = init_cl(env[0]);
	for (int i = 1; env[i]; ++i)
		insert_end(&element, env[i]);
	return (element);
}

void wait_com(char *str, char **env, list_path *list_p)
{
	pid_t	pid;

	if ((pid = fork()) == 0)
		check_arg(str, list_p, env);
	else
		waitpid(pid, 0, 0);
}

int fct_while(char *str, char **env)
{
	int		value = 0;
	list_path	*list_p = init_chain_path(env);

	while (1) {
		my_putstr("[Dis_is_de_we]$> ");
		value = read(0, str, 50);
		str[value - 1] = '\0';
		wait_com(str, env, list_p);
	}
	return (0);
}

int main(int argc, char *argv[], char **env)
{
	char	*str = malloc(55);

	(void)argv;
	if (argc > 1) {
		my_puterror("Too many arguments !\n");
		return (84);
	}
	fct_while(str, env);
	return (0);
}
