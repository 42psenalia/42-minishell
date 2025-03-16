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

# include "../parser.h"
# include "../shellstart.h"
# include <stdbool.h>

extern int		g_signal;

// ID COMMS
bool			builtin_check(char *name);
bool			parent_builtin(char *name);

// BASIC COMMANDS
t_exit_status	parbuiltin_execute(t_command *cmd, t_shell_data *dat);
t_exit_status	builtin_execute(t_command *cmd, t_shell_data *dat);
char			*ft_getcwd(void);
t_exit_status	builtin_cd(int argc, char **argv, t_shell_data *data);
t_exit_status	builtin_exit(t_command *cmd, t_shell_data *data);
t_exit_status	builtin_export(int argc, char **argv, t_shell_data *data);
t_exit_status	builtin_unset(int argc, char *argv, t_shell_data *data);
t_exit_status	builtin_echo(int argc, char **argv, t_shell_data *data);
t_exit_status	builtin_env(int argc, char **argv, t_shell_data *data);
t_exit_status	builtin_pwd(int argc, char **argv, t_shell_data *data);

#endif
