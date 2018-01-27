/*
** EPITECH PROJECT, 2017
** get_next_line.c
** File description:
** blabla
*/

#include "../include/get_next_line.h"

char *fill_str2(char *str, char *buffer, int fd)
{
	int	i = 0;
	int	j = 0;
	int	check = 1;

	for (i = 0; buffer[i] != '\n' && buffer[i]; ++i) {
		str[j] = buffer[i];
		str = my_realloc(str);
		++j;
	}
	if (buffer[j] && buffer[j] == '\n') {
		str[j] = '\0';
		return (str);
	}
	while ((check = read(fd, buffer, READ_SIZE)) > 0) {
		for (i = 0; buffer[i] != '\n' && buffer[i]; ++i) {
			str[j] = buffer[i];
			str[j + 1] = '\0';
			str = my_realloc(str);
			++j;
		}
		if (buffer[i] == '\n')
			break;
	}
	str[j] = '\0';
	return (str);
}

char *my_realloc(char *str)
{
	static int	size = 1020;
	char		*tmp = NULL;
	int		i = 0;
	int		j = 0;

	while (str[j] != '\0')
		j = j + 1;
	if (j == size) {
		size = size * 2;
		tmp = malloc(sizeof(char) * size);
		for (i = 0; i < j; ++i)
			tmp[i] = str[i];
		free(str);
		tmp[i] = '\0';
		return (tmp);
	}
	return (str);
}

char *fill_str(char *str, char *buffer, int order)
{
	static int	status = 0;
	static int	j = 0;

	if (status == 0)
		str = malloc(sizeof(char) * 1024);
	if (order == 0) {
		for (int i = 0; buffer[i]; ++i) {
			str[j] = buffer[i];
			str[j + 1] = '\0';
			str = my_realloc(str);
			++j;
		}
	}
	if (order == 1) {
		j = 0;
		for (int i = 0; buffer[i] != '\n' && buffer[i]; ++i) {
			str[j] = buffer[i];
			str[j + 1] = '\0';
			str = my_realloc(str);
			++j;
		}
	}
	status = 1;
	str[j] = '\0';
	return (str);
}

char *decal_str(char *str)
{
	int	i = 0;
	int	j = 0;

	while (str[i] != '\n' && str[i] != '\0')
		++i;
	if (i != 0)
		++i;
	while (str[i] != '\0') {
		str[j] = str[i];
		++i;
		++j;
	}
	str[j] = '\0';
	return (str);
}

char *get_next_line (int fd)
{
	int		check = 1;
	static int	status = 0;
	static char	*str;
	char		buffer[READ_SIZE];
	char		*array = malloc(sizeof(char) * 1024);

	if (array == NULL)
		return (NULL);
	if (fd < 0)
		return (NULL);
	if (status == 0) {
		while ((check = read(fd, buffer, READ_SIZE)) > 0) {
			buffer[check] = '\0';
			str = fill_str(str, buffer, 0);
			if (fd == 0) {
				array = fill_str2(array, buffer, fd);
				return (array);
			}
		}
		if (check == 0 && fd == 0)
			return (NULL);
	}
	array = fill_str(array, str, 1);
	str = decal_str(str);
	if (array[0] == '\0')
		return (NULL);
	return (array);
}
