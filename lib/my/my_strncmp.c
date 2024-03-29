/*
** EPITECH PROJECT, 2017
** my_strncmp
** File description:
** my_strncmp
*/


int my_strcmp(char const *s1, char const *s2)
{
	int	i = 0;

	while (s1[i] == s2[i] && s1[i] && s2[i])
		++i;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	else if (s1[i] > s2[i])
		return (1);
	else
		return (2);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
	int	i = 0;

	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
		++i;
	if ((s1[i] == '\0' && s2[i] == '\0') || i == n)
		return (0);
	else if (s1[i] > s2[i])
		return (1);
	else
		return (2);
}
