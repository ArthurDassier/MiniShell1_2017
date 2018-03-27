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
	char		*path_name;
	list_path	*next;
};

#endif
