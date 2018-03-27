/*
** EPITECH PROJECT, 2017
** chainlist.c
** File description:
** blabla
*/

#include "my.h"
#include "minishell1.h"
#include "printf.h"

list_path *init_cl(char *path)
{
	list_path	*element = malloc(sizeof(list_path));

	element->path_name = path;
	element->next = NULL;
	return (element);
}

void insert_begin(list_path **first_elem, char *path)
{
	list_path	*new_elem = malloc(sizeof(list_path));

	if (new_elem == NULL)
		return;
	new_elem->path_name = path;
	new_elem->next = *first_elem;
	(*first_elem) = new_elem;
}

void insert_end(list_path **first_elem, char *path)
{
	list_path	*new_elem = malloc(sizeof(list_path));
	list_path	*actual = (*first_elem);

	if (new_elem == NULL)
		return;
	new_elem->path_name = path;
	new_elem->next = NULL;
	while (actual->next != NULL)
		actual = actual->next;
	actual->next = new_elem;
}

void del_elem_list(list_path **first_elem, char *path)
{
	list_path	*actual = (*first_elem);
	int		i = 0;

	while (actual->next != NULL) {
		for (i = 0; actual->next->path_name[i] != '=' && path[i]; ++i) {
			if (actual->next->path_name[i] != path[i])
				break;
		}
		if (actual->next->path_name[i] == '=') {
			actual->next = actual->next->next;
			return;
		}
		actual = actual->next;
	}
}

void print_list(list_path *liste)
{
	list_path	*temp;

	temp = liste;
	while (temp != NULL) {
		my_printf("%s\n", temp->path_name);
		temp = temp->next;
	}
}
