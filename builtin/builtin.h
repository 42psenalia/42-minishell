/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:26:47 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/11 15:26:47 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../minishell.h"
# include "../shellstart.h"
# include "../libft/libft.h"
# include "../parser/parser.h"
# include <stdbool.h>

extern int					g_signal;
typedef int					t_exit_status;
typedef struct s_shell_data	t_shell_data;
typedef struct s_ast		t_ast;

// ID COMMS
int				builtin_check(char *name);
int				parent_builtin(char *name);

// BASIC COMMANDS
t_exit_status	parbuiltin_execute(t_ast *cmd, t_shell_data *dat);
t_exit_status	builtin_execute(t_ast *cmd, t_shell_data *dat);
t_exit_status	builtin_cd(int argc, char **argv, t_shell_data *data);
t_exit_status	builtin_exit(t_ast *cmd, t_shell_data *data);
t_exit_status	builtin_export(int argc, char **argv, t_shell_data *data);
t_exit_status	builtin_unset(int argc, char **argv, t_shell_data *data);
t_exit_status	builtin_echo(int argc, char **argv, t_shell_data *data);
t_exit_status	builtin_env(int argc, char **argv, t_shell_data *data);
t_exit_status	builtin_pwd(int argc, char **argv, t_shell_data *data);

#endif
