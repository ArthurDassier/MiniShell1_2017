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

int check_env(char *str);
int check_setenv(char *str);
int check_unsetenv(char *str);
void check_arg(char *str, list_path *list_p, char **env);
void bin_tests(char *str, list_path *list_p, char **env);
char *lead_path(char *str, char *path, int *j);
char **set_buffer(char *tmp);
char **multi_arg(char *tmp, char **buffer, int i);
list_path *init_cl(char *path);
void insert_begin(list_path **first_elem, char *path);
void insert_end(list_path **first_elem, char *path);
void del_elem_list(list_path **first_elem, char *path);
void print_list(list_path *liste);
void error_handler(char *str);
void wait_com(char *str, char **env, list_path *list_p);
list_path *init_chain_path(char **env);
int fct_while(char *str, char **env);
int get_path(char **env);
void modif_env(char *str, list_path *list_p);
void del_env(char *str, list_path *list_p);
void cd_arg(char *str, list_path *list_p, char **env);
char *my_strcat_pwd(char *dest, char const *src);

#endif
