/*
** EPITECH PROJECT, 2017
** cd_call.c
** File description:
** blabla
*/

#include "my.h"

int get_pwd(char **env)
{
	for (int i = 0; env[i]; ++i) {
		if (env[i][0] == 'P' && env[i][1] == 'W' &&
			env[i][2] == 'D' && env[i][3] == '=')
			return (i);
	}
	return (-1);
}

void modif_path(char **env, list_path *list_p)
{
	int		i = get_pwd(env);
	char		*buff = malloc(sizeof(char) * 1024);
	char		*buff2 = malloc(sizeof(char) * 1024);
	list_path	*temp = list_p;

	getcwd(buff, 1024);
	while (i != 0) {
		temp = temp->next;
		--i;
	}
	my_strcpy(buff2, "PWD=");
	buff2 = my_strcat_pwd(buff2, buff);
	temp->path_name = buff2;
}

void cd_arg(char *str, list_path *list_p, char **env)
{
	char	*tmp = malloc(sizeof(char) * 1024);
	int	i = 3;
	int	j = 0;

	while (str[i] != '\0') {
		tmp[j] = str[i];
		++i;
		++j;
	}
	tmp[j] = '\0';
	chdir(tmp);
	modif_path(env, list_p);
}
