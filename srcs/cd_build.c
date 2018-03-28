/*
** EPITECH PROJECT, 2018
** cd_build.c
** File description:
** Arthur
*/

#include "my.h"
#include "minishell1.h"
#include "printf.h"

static char *go_home(list_path *my_env)
{
	list_path	*tmp = my_env;
	char		*str;
	int		i = 5;
	int		j = 0;

	while (tmp != NULL && my_strncmp(tmp->name, "HOME=", 4) != 0)
		tmp = tmp->next;
	str = malloc(sizeof(char) * my_strlen(tmp->name));
	while (tmp->name[i] != '\0') {
		str[j] = tmp->name[i];
		++i;
		++j;
	}
	str[j] = '\0';
	return (str);
}

void the_cd(char *tab, list_path *my_env)
{
	char	*path = tab;
//	char	*old_pwd = getcwd(old_pwd, 4096);

	if (tab == NULL || tab[0] == '~')
		path = go_home(my_env);
	if (chdir(path) == -1) {
		my_printf("%s: No such file or directory.\n", tab);
		return;
	}
}
