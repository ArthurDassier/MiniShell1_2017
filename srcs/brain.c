/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** blabla
*/

#include "my.h"

int main(int argc, char *argv[])
{
	char	*str[] = {argv[1], NULL, NULL};

	printf("PID : %d\n", getpid());
	execve(str[0], str, NULL);
	return (0);
}
