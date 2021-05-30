/*
** EPITECH PROJECT, 2021
** B-PSU-101-PAR-1-4-minishell1-clement.mikula
** File description:
** get_path
*/

#include <stdlib.h>
#include <string.h> //strtok
#include "my.h"

static int get_path_line(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
    {
        if (env[i][0] == 'P' &&
            env[i][1] == 'A' &&
            env[i][2] == 'T' &&
            env[i][3] == 'H')
            return i;
    }
    return -1;
}

static void clean_path(char **env, int path_line)
{
    int len = my_strlen(env[path_line]);
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < len; i++)
        {
            env[path_line][i] = env[path_line][i + 1];
        }
    }
}

static char **get_all_path(char **env, int path_line)
{
    char **str = malloc(sizeof(char *) * 11);
    for (int i = 0; i < 11; i++)
        str[i] = malloc(sizeof(char) * 50);
    str[10] = NULL;
    strtok(env[path_line], ":");
    for (int i = 0; str[i] != NULL; i++)
        str[i] = strtok(NULL, ":");
    return str;
}

char **get_path(char **env)
{
    int path_line = get_path_line(env);
    clean_path(env, path_line);
    char **all_path = get_all_path(env, path_line);
    return all_path;
}