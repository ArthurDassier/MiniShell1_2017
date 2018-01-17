/*
** EPITECH PROJECT, 2017
** ls_command.c
** File description:
** blabla
*/

#include "my.h"

char **set_buffer(char *tmp)
{
	int	i = 0;
	int	j = 0;
	int	count = 0;
	int	count2 = 0;
	char	*arg = malloc(100);
	char 	**buffer = malloc(100);

	buffer[0] = malloc(100);
	buffer[1] = malloc(100);
	while (tmp[i] != ' ' && tmp[i] != '\0') {
		++i;
	}
	if (tmp[i] == '\0') {
		buffer[0] = tmp;
		buffer[1] = NULL;
		return (buffer);
	}
	if (tmp[i] == ' ')
		tmp[i] = '\0';
	j = i + 1;
	while (tmp[j] != '\0') {
		arg[count] = tmp[j];
		++j;
		++count;
	}
	arg[count] = '\0';
	while (tmp[count2] != '\0') {
		buffer[0][count2] = tmp[count2];
		++count2;
	}
	buffer[0][count2] = '\0';
	count2 = 0;
	while (arg[count2] != '\0') {
		buffer[1][count2] = arg[count2];
		++count2;
	}
	buffer[2] = NULL;
	return (buffer);
}

char *lead_path(char *str, char *path, int *j)
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
	char		**buf;
	list_path	*temp;
	struct stat	sb;
	int		i = get_path(env);
	int		letter = 5;
	char		*tmp;

	temp = list_p;
	while (i != 0) {
		temp = temp->next;
		--i;
	}
	tmp = lead_path(str, temp->path_name, &letter);
	while (stat(tmp, &sb) == -1 && letter < my_strlen(temp->path_name)) {
		tmp = lead_path(str, temp->path_name, &letter);
		buf = set_buffer(tmp);
		++letter;
	}
	execve(tmp, buf, env);
	error_handler(str);
}
