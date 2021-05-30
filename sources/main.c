/*
** EPITECH PROJECT, 2020
** 0
** File description:
** 0
*/

#include "my.h"
#include "minishell.h"

#include <signal.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>

#include <string.h> //strtok
#include <stdio.h>

#include <unistd.h>

char **malloc_arg()
{
    int nbstr = 10;
    char **arg;
    arg = malloc(sizeof(char *) * nbstr * 2);
    for (int i = 0; i <= nbstr; i++)
        arg[i] = malloc(sizeof(char) * 100);
    return arg;
}

char *test_path(char *word, char **path)
{
    char *str;
    for (int i = 0; path[i] != NULL; i++)
    {
        str = my_strcat(path[i], "/");
        //printf("str = %s\n", str);
        str = my_strcat(str, word);
        //printf("str = %s\n", str);
        int res = access(str, X_OK);
        //printf("res = %d\n", res);
        if (res == 0) {
            word = str;
            return word;
        }
    }
    return NULL;
}

int main(int argc, char **argv, char **env)
{
    char **path = get_path(env);
    //for (int i = 0; path[i] != NULL; i++)
    //    printf("%s\n", path[i]);

    char *res = malloc(sizeof(char) * 100);
    char **arg = malloc_arg();
    char *word = malloc(sizeof(char) * 100);
    size_t size = 0;

    my_putstr("> ");
    while (getline(&word, &size, stdin) != -1)
    {
        word[my_strlen(word) - 1] = '\0';
        segmentation(res, arg);
        //segmentation(word, arg);
        //for (int i = 0; arg[i] != NULL; i++)
        //    printf("arg[%d] = %s\n", i , arg[i]);
        char *res = test_path(word, path);
        segmentation(res, arg);
        //printf("res1 = %s\n", res);
        do_fork(env, arg);
        wait(NULL);
        my_putstr("> ");
    }
    free_all(word, res, arg);
    my_putchar('\n');
}