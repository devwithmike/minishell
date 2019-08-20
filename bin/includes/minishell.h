/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 09:25:23 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/20 10:16:16 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <sys/stat.h>
# include <signal.h>

char	**m_env;

int		execute_args(char **cmds);
int		exec_tilda(char **cmd);
int		check_sys(char **cmd);
int		exec_cd(char **cmd);
void	free_er(char **str);
void	print_path(void);
int		print_env(char **cmd);
void	pop_env(char **env);
int		home_path_len(void);
int		reset_env(char *key, char *value);
void	exec_prev(void);
int		exec_sys(char **cmd);
char	*get_path(char *com);
int		exec_echo(char **cmd);
int		set_env(char **cmd);
int		unset_env(char **cmd);
char	*end_quote(char *str, char q);
int		sys_call(char **cmd, char *path);
char	*do_path(char *bin, char *com);
char	*get_env(char *str);
void	exec_path(char *path);
void	exec_env(char **cmd);
int		exec_help(void);
void	error_found(char *path, char *cmd);
int		error_params(char **cmd, int i);
int		exec_author(void);
void	proc_signal_handler(int signo);
void	handle_sigint(int sig);
void	zsh_level(void);

#endif
