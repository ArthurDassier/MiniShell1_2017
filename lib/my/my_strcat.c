/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** strcat
*/

#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
	int	i = 0;
	int	j = 0;
	char	*tmp = malloc(55);

	while (dest[i] != '\0') {
		tmp[i] = dest[i];
		++i;
	}
	while (src[j] != '\0') {
		tmp[i] = src[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	return (tmp);
}
