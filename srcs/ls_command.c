/*
** EPITECH PROJECT, 2017
** ls_command.c
** File description:
** blabla
*/

#include "my.h"

char *test1(char *str, char *path, int *j)
{
	char	*tmp = malloc(100);
	int	count = 0;

	while (path[*j] != ':' && path[*j]) {
		tmp[count] = path[*j];
		++*j;
		++count;
	}
	tmp = my_strcat(tmp, str);
	return (tmp);
}

void ls_tests(char *str, list_path *list_p, char **env)
{
	char		*buf[] = {"NULL", NULL};
	list_path	*temp;
	struct stat	sb;
	int		j = 0;
	int		i = get_path(env);
	int		letter = 5;
	char		*tmp;

	temp = list_p;
	while (j != i) {
		temp = temp->next;
		++j;
	}
	tmp = test1(str, temp->path_name, &letter);
	while (stat(tmp, &sb) == -1 && letter < my_strlen(temp->path_name)) {
		tmp = test1(str, temp->path_name, &letter);
		++letter;
	}
	execve(tmp, buf, env);
	error_handler(str);
}
