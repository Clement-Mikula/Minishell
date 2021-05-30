/*
** EPITECH PROJECT, 2021
** B-PSU-101-PAR-1-4-minishell1-clement.mikula
** File description:
** minishell
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

char *my_strcat(char *dest, char const *src);
void do_fork(char **env, char **arg);
void segmentation(char *str, char **arg);
void free_all(char *word, char *res, char **arg);
char **my_array_dup(char **tab);
char **get_path(char **env);

#endif /* !MINISHELL_H_ */
