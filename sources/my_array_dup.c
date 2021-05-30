/*
** EPITECH PROJECT, 2021
** B-PSU-101-PAR-1-4-minishell1-clement.mikula
** File description:
** my_array_dup
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

static int count_rows(char **tab)
{
    int array = 0;
    for (; tab[array] != NULL; ++array);
    return array;
}

static int count_cols(char **tab)
{
    int max_line = 0;
    for (int i = 0; tab[i] != NULL; i++)
    {
        if (my_strlen(tab[i]) > max_line)
            max_line = my_strlen(tab[i]);
    }
    return max_line;
}

static char **malloc_2d_array(int rows, int cols)
{
    char **tab = malloc(sizeof(char *) * (rows + 1));
    for (int i = 0; i < rows; i++) {
        tab[i] = malloc(sizeof(char) * (cols + 1));
        tab[i][cols] = '\0';
    }
    tab[rows] = NULL;
    return tab;
}

char **my_array_dup(char **tab)
{
    int rows = count_rows(tab);
    int cols = count_cols(tab);
    //printf("rows = %d, cols = %d\n", rows, cols);
    char **res = malloc_2d_array(rows, cols);
    for (int i = 0; tab[i] != NULL; i++)
        my_strcpy(res[i], tab[i]);
    //for (int i = 0; res[i] != NULL; i++)
    //    printf("res[%d] = %s\n", i, res[i]);
    
    return res;
}