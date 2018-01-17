/*
** EPITECH PROJECT, 2017
** minishell1.h
** File description:
** blabla
*/

#ifndef MINI_SHELL_H
#define MINI_SHELL_H

#include "my.h"

typedef struct list_path list_path;

struct list_path
{
	char		*path_name;
	list_path	*next;
};

list_path *init_cl(char *path);
void insert_begin(list_path **first_elem, char *path);
void insert_end(list_path **first_elem, char *path);
void print_list(list_path *liste);
void error_handler(char *str);
void ls_tests(char *str, list_path *list_p, char **env);
void wait_com(char *str, char **env, list_path *list_p);
char *lead_path(char *str, char *path, int *j);
list_path *init_chain_path(char **env);
int get_path(char **env);
int fct_while(char *str, char **env);

#endif
