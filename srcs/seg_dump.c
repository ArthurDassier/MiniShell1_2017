/*
** EPITECH PROJECT, 2017
** seg_dump.c
** File description:
** blabla
*/

#include "my.h"

void fault(int wstatus)
{
	if (WTERMSIG(wstatus))
	write(2, "segmentation fault\n", 19);
	if (WCOREDUMP(wstatus))
		write(2, "core dumped\n", 12);
}
