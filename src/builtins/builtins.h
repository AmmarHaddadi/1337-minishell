/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 21:39:41 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/06/07 21:39:41 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdbool.h>

typedef struct s_command	t_command;
typedef struct s_shellvar	t_shellvar;

// builtins
int							echo(t_command *command);
int							cd(t_command *command, char *home);
int							pwd(void);
int							export(t_shellvar *vars, t_command *command);
int							unset(t_command *command, t_shellvar **vars);
int							env(t_shellvar *vars);
int							builtin_exit(t_command *cmd);

// helpers
void						bubble_sort_shellvars(t_shellvar *head);
void						updatevar(char *key, char *val, t_shellvar *vars,
								bool exported);
t_shellvar					*envtoll(char **env);
char						**varstomatrix(t_shellvar *vars);
char						*getvar(char *key, t_shellvar *vars);
void						freeenv(t_shellvar *vars);
