/*
** EPITECH PROJECT, 2017
** ls_command.c
** File description:
** blabla
*/

#include "my.h"

char **multi_arg(char *tmp, char **buffer, int i)
{
	int	j = 1;
	int	count = 0;

	buffer[0] = tmp;
	while (tmp[i] != '\0') {
		if (tmp[i] == ' ') {
			++j;
			buffer[j] = malloc(100);
			count = 0;
			++i;
		}
		buffer[j][count] = tmp[i];
		++count;
		++i;
	}
	buffer[j + 1] = NULL;
	return (buffer);
}

char **set_buffer(char *tmp)
{
	int	i = 0;
	char	**buffer = malloc(100);

	buffer[0] = malloc(100);
	buffer[1] = malloc(100);
	while (tmp[i] != ' ' && tmp[i] != '\0')
		++i;
	if (tmp[i] == '\0') {
		buffer[0] = tmp;
		buffer[1] = NULL;
		return (buffer);
	}
	tmp[i] = '\0';
	return (multi_arg(tmp, buffer, i + 1));
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

void bin_tests(char *str, list_path *list_p, char **env)
{
	char		**buf;
	list_path	*temp;
	int		i = get_path(env);
	int		letter = 5;
	char		*tmp;

	temp = list_p;
	while (i != 0) {
		temp = temp->next;
		--i;
	}
	tmp = lead_path(str, temp->path_name, &letter);
	while (access(tmp, F_OK) == -1 && access(tmp, X_OK) == -1
		&& letter < my_strlen(temp->path_name)) {
		tmp = lead_path(str, temp->path_name, &letter);
		buf = set_buffer(tmp);
		++letter;
	}
	execve(tmp, buf, env);
	error_handler(str);
}
