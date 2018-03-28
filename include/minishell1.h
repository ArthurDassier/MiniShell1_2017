/*
** EPITECH PROJECT, 2017
** minishell1.h
** File description:
** blabla
*/

#ifndef MINI_SHELL_H
#define MINI_SHELL_H

typedef struct list_path list_path;

struct list_path
{
	char		*name;
	list_path	*next;
};


list_path *init_cl(char **env);
list_path *insert_end(list_path **first_elem, char *path);

#endif
