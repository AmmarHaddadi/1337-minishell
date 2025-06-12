/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddadi <ahaddadi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 23:07:44 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/06/09 23:07:44 by ahaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef EXECUTION_H
# define EXECUTION_H
# include <stdbool.h>
# include <sys/_types/_pid_t.h>

typedef struct s_command	t_command;
typedef struct s_shellvar	t_shellvar;
typedef struct s_redir		t_redir;

// #fuck 42 norme
struct						s_maestro
{
	int						clen;
	pid_t					*pids;
	int						**pipes;
};

int							bin(t_command *cmd, t_shellvar *vars);
int							maestro(t_command *cmd, t_shellvar *vars, int *xt);

// helper
char						*getvalidpath(t_command *cmd, char *path);
bool						setupfd(t_redir *red);
int							**setuppipes(int len);
int							cmdlen(t_command *cmd);
void						fcp(int **pipes, int len);
void						freecmd(t_command *cmd);
void						set_xt(t_command *cmd, int *xt);
bool						routeout(int *ofd, int outmode, char *redfile);
void						cp(int **pipes, int max);
void						hndlfrkerr(int i, int clen, int *pids, int **pipes);
int							getcode(int *pids, int clen);
int							dofork(struct s_maestro ms, int i, t_command *cmd,
								t_shellvar *vars);

#endif
