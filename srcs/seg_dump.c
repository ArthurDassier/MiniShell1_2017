/*
** EPITECH PROJECT, 2017
** seg_dump.c
** File description:
** blabla
*/

#include "my.h"

void fault(int wstatus)
{
	int	i = 0;

	if (WTERMSIG(wstatus)) {
		write(2, "Segmentation fault", 19);
		i = 1;
	}
	if (WCOREDUMP(wstatus)) {
		write(2, " (core dumped)", 14);
		i = 1;
	}
	if (i == 1)
		write(1, "\n", 1);
}
