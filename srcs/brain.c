/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** blabla
*/

#include "my.h"

int main()
{
	char	*str = malloc(55);
	int	lol = 0;
	char	*buf[] = {"Tamer", NULL};
	char	bin[5] = "/bin/";
	pid_t	pid;

	while (1) {
		my_putstr("ZSH_2000: ");
		lol = read(0, str, 50);
		str[lol - 1] = '\0';
		str = my_strcat(bin, str);
		if ((pid = fork()) == 0)
			execve(str, buf, NULL);
		else
			waitpid(pid, 0, 0);
	}
	return (0);
}
