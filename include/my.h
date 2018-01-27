/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** mes_prototypes
*/

#ifndef MYLIB_H
#define MYLIB_H

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <dirent.h>
#include "minishell1.h"
#include "printf.h"
#include "get_next_line.h"

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcat(char *dest, char const *src);
int my_put_nbr_base(int nb, char *base);
long my_put_nbr_base_long(long long nb, char *base);
char *my_realloc(char *str);
void my_puterror(char *str);
int cti(char c);
char itc(int nb);

#endif
