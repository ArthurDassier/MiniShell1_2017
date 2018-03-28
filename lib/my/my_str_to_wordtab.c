/*
** EPITECH PROcountECT, 2018
** my_str_to_wordtab.c
** File description:
** Arthur
*/

#include <stdlib.h>

int my_strlen(char *);

char **my_path_to_wordtab(char *str, int nb)
{
	char	**tab = malloc(sizeof(char *) * (my_strlen(str) + 1));
	int	i = 0;
	int	j = 0;

	tab[i] = malloc(sizeof(char) * my_strlen(str));
	for (int count = nb; str[count] != '\0'; ++count) {
		if (str[count] == ':') {
			tab[i][j] = '\0';
			++i;
			tab[i] = malloc(sizeof(char) * (my_strlen(str) + 1));
			j = 0;
			++count;
		}
		tab[i][j] = str[count];
		++j;
	}
	tab[i][j] = '\0';
	tab[i + 1] = NULL;
	return (tab);
}

void count_space(char *str, int *count)
{
	while (str[*count] == ' ' || str[*count] == '\t')
		++*count;
	--*count;
}

char **my_str_to_wordtab(char *str)
{
	char	**tab = malloc(sizeof(char *) * (my_strlen(str) + 1));
	int	i = 0;
	int	j = 0;

	tab[i] = malloc(sizeof(char) * (my_strlen(str) + 1));
	for (int count = 0; str[count] != '\0'; ++count) {
		if (str[count] == ' ' || str[count] == '\t') {
			count_space(str, &count);
			tab[i][j] = '\0';
			++i;
			tab[i] = malloc(sizeof(char) * my_strlen(str));
			j = 0;
			++count;
		}
		tab[i][j] = str[count];
		++j;
	}
	tab[i][j] = '\0';
	tab[i + 1] = NULL;
	return (tab);
}
