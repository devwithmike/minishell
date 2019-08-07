/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 09:25:23 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/07 09:08:05 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>

char	**m_env;
char	*home;

int		execute_args(char **cmds);
int		check_sys(char **cmds);
int		exec_cd(char *cmd);
void	free_er(char **str);
void	print_path(void);
int		print_env(void);
void	get_home(char *path);
void	pop_env(char **env);
int		home_path_len(void);
void	reset_env(char *key, char *value);
void	exec_prev(void);
int exec_sys(char **cmds);

#endif
