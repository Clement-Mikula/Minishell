/*
** EPITECH PROJECT, 2021
** B-PSU-101-PAR-1-4-minishell1-clement.mikula
** File description:
** segmentation
*/

#include <stddef.h>
#include <stdlib.h>

void segmentation(char *str, char **arg)
{
    int j = 0;
    int z = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            arg[j][z] = '\0';
            j++;
            z = 0;
        }
        else
        {
            arg[j][z] = str[i];
            z++;
        }
    }
    arg[j + 1] = NULL;
}