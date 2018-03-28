/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** blabla
*/

#include "my.h"
#include "get_next_line.h"
#include "minishell1.h"
#include "printf.h"
#include <sys/types.h>
#include <sys/wait.h>

int try_env(char **tab, list_path *my_env)
{
	if (my_strcmp(tab[0], "env") == 0 ||
	(my_strcmp(tab[0], "setenv") == 0 && !tab[1])) {
		print_list(my_env);
		return (0);
	}
	if (my_strcmp(tab[0], "setenv") == 0) {
		my_setenv(tab, my_env);
		return (0);
	}
	if (my_strcmp(tab[0], "unsetenv") == 0) {
		del_elem_list(&my_env, tab[1]);
		return (0);
	}
	return (1);
}

int try_build(char **tab, list_path *my_env)
{
	if (try_env(tab, my_env) == 0)
		return (0);
	if (my_strcmp(tab[0], "exit") == 0)
		exit(my_getnbr(tab[1]));
	if (my_strcmp(tab[0], "cd") == 0) {
		the_cd(tab[1], my_env);
		return (0);
	}
	return (1);
}

char **reset_env(list_path *my_env, char **new_env)
{
	list_path	*temp = my_env;
	int		i = 0;

	while (temp != NULL) {
		temp = temp->next;
		++i;
	}
	new_env = malloc(sizeof(char *) * (i + 1));
	i = 0;
	temp = my_env;
	while (temp != NULL) {
		new_env[i] = temp->name;
		temp = temp->next;
		++i;
	}
	return (new_env);
}

int shell(list_path *my_env, char **new_env, char **tab)
{
	char	*path;
	char	**com;
	char	*str;

	while (42) {
		new_env = reset_env(my_env, new_env);
		path = find_path(my_env);
		com = my_path_to_wordtab(path, 5);
		my_putstr("[Darth_Shell]$> ");
		str = get_next_line(0);
		if (str == NULL) {
			my_putstr("exit\n");
			return (0);
		}
		tab = my_str_to_wordtab(str);
		if (try_build(tab, my_env) == 1)
			test_path(tab, com, new_env);
	}
	return (0);
}

int main(int ac, char *av[], char **env)
{
	list_path	*my_env = init_cl(env);
	char		**new_env = NULL;
	char		**tab = NULL;
	int		i = 1;

	(void) ac;
	(void) av;
	if (my_env == NULL)
		return (84);
	while (env[i]) {
		insert_end(&my_env, env[i]);
		++i;
	}
	if (shell(my_env, new_env, tab) == 84)
		return (84);
	return (0);
}
