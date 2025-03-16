/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:58:55 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 12:58:55 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include "..libft/libft.h"
#include "../parser/parser.h"
#include "../shellstart.h"
#include "builtin.h"

static bool	is_number(char *str)
{
	int		num;
	char	temp;
	int		cmp;

	if (*str == '+')
		str++;
	num = ft_atoi(str);
	temp = ft_itoa(num);
	if (temp == NULL)
		return (false);
	cmp = ft_strcmp(str, temp);
	free(temp);
	if (cmp == 0)
		return (true);
	return (false);
}

static int	numarg_error(char *str)
{
	ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
	return (2);
}

static bool	get_exit_status(t_exit_status *status, t_command *cmd)
{
	if (cmd->argc > 2)
	{
		if (is_number(cmd->argv[1]))
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", \
				STDERR_FILENO);
			return (false);
		}
		else
			*status = numarg_error(cmd->argv[1]);
	}
	else if (cmd->argc == 2)
	{
		if (is_number(cmd->argv[1]))
			*status = ft_atoi(cmd->argv[1]) % 256;
		else
			*status = numarg_error(emd->argv[1]);
	}
	return (true);
}

t_exit_status	builtin_exit(t_command *cmd, t_shell_data *data)
{
	t_exit_status	exitstat;

	exitstat = data->exit_status;
	if (cmd)
	{
		printf("exit\n");
		if (!get_exit_status(&exit_status, cmd))
			return (1);
		free_command(cmd);
	}
	freeshell(data);
	restore_terminal_settings();
	exit(exit_status);
}
