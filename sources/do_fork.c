/*
** EPITECH PROJECT, 2021
** B-PSU-101-PAR-1-4-minishell1-clement.mikula
** File description:
** fork
*/

#include <unistd.h>
#include <stdio.h>

void do_fork(char **env, char **arg)
{
    if (fork() == 0)
    {
        if (execve(arg[0], arg, env) == -1)
            perror("error");
    }
}
