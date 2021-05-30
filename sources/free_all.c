/*
** EPITECH PROJECT, 2021
** B-PSU-101-PAR-1-4-minishell1-clement.mikula
** File description:
** free_all
*/

#include <stdlib.h>

void free_all(char *word, char *res, char **arg)
{
    free(word);
    free(res);
    for (int i = 0; arg[i] != NULL; i++)
        free(arg[i]);
    free(arg);
}