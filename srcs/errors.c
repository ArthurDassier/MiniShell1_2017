/*
** EPITECH PROJECT, 2017
** errors.c
** File description:
** blabla
*/

#include "my.h"

void error_handler(char *str)
{
	my_puterror("Command not found: ");
	my_puterror(str);
	my_puterror("\n");
	exit(1);
}
