/*
** EPITECH PROJECT, 2021
** B-PSU-101-PAR-1-4-minishell1-clement.mikula
** File description:
** my_strcat
*/

#include <sys/types.h>
#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src)) + 1);
    size_t dest_len = my_strlen(dest);
    size_t i;

    my_strcpy(str, dest);
    for (i = 0; src[i] != '\0'; i++)
        str[dest_len + i] = src[i];
    str[dest_len + i] = '\0';

    return str;
}