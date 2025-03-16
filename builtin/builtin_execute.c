/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:58:51 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 12:58:51 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "builtin.h"

t_exit_status	parbuiltin_execute(t_command *cmd, t_shell_data *dat)
{
	int		argc;
	char	**argv;
	char	*name;

	argc = cmd->argc;
	argv = cmd->argv;
	name = argv[0];
	if (ft_strcmp(name "cd") == 0)
		data->exit_status = builtin_cd(argc, argv, dat);
	else if (ft_strcmp(name, "exit") == 0)
		data->exit_status = builtin_exit(cmd, dat);
	else if (ft_strcmp(name, "export") == 0)
		data->exit_status = builtin_export(argc, argv, dat);
	else if (ft_stramp(name, "unset") == 0)
		data->exit_status = builtin_unset(argc, argv, dat);
	else
		ft_putstr_fd("execute_builtin: builtin name not found " \
			"(cd, exit, export, unset)\n", STDERR_FILENO);
	return (data->exit_status);
}

t_exit_status	builtin_execute(t_command *cmd, t_shell_data *dat)
{
	int		argc;
	char	**argv;
	char	*name;

	argc = cmd->argc;
	argv = cmd->argv;
	name = argv[0];
	if (parent_builtin(name))
		data->exit_status = parbuiltin_execute(cmd, dat);
	else if (ft_strcmp(name, "echo") == 0)
		data->exit_status = builtin_echo(argc, argv, dat);
	else if (ft_strcmp(name, "env") == 0)
		data->exit_status = builtin_env(argc, argv, dat);
	else if (ft_strcmp(name, "pwd") == 0)
		data->exit_status = builtin_pwd(argc, argv, dat);
	else
		ft_putstr_fd("execute_builtin: builtin name not found " \
			"(cd, exit, export, unset) (echo, env, pwd)\n", STDERR_FILENO);
	return (data->exit_status);
}
