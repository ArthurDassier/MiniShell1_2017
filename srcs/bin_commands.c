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
			buffer[j] = malloc(sizeof(char) * 100);
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
	char	**buffer = malloc(sizeof(char) * 100);

	buffer[0] = malloc(sizeof(char) * 100);
	buffer[1] = malloc(sizeof(char) * 100);
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
	char	*tmp = malloc(sizeof(char) * 1024);
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
	int		letter = 5;
	char		*tmp;

	temp = list_p;
	for (int i = get_path(env); i != 0; i--)
		temp = temp->next;
	tmp = lead_path(str, temp->path_name, &letter);
	while (access(tmp, F_OK) == -1 && access(tmp, X_OK) == -1
	&& letter < my_strlen(temp->path_name)) {
		tmp = lead_path(str, temp->path_name, &letter);
		buf = set_buffer(tmp);
		++letter;
	}
	execve(tmp, buf, env);
	str[my_strlen(str)] = '\0';
	execve(str, buf, env);
	error_handler(str);
}
