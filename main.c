/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:52:19 by tanselbay1        #+#    #+#             */
/*   Updated: 2025/03/11 14:36:43 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellstart.h"
#include "libft/libft.h"
#include "builtin/builtin.h"
#include "execution/execute.h"
#include <errno.h>
#include <stdio.h>

static void	detect_line(char *line, t_shell_data *data)
{
	t_commands	*commands;
	int			progress;

	if (ft_strlen(line) == 0)
	{
		data->exit_status = SUCCESS;
		return ;
	}
	commands = NULL;
	progress = parser(line, data, &commands);
	if (progress == EINVAL || commands == NULL)
	{
		data->exit_status = ENOENT;
		return ;
	}
	else if (progress == ENOMEM)
		exitshell(NULL, data);
	data->exit_status = lsh_execute(&commands, data);
}

static void	lsh_loop(t_shell_data *data)
{
	char		*line;
	t_commands	*args;

	g_signal = READ_MODE;
	line = lsh_read_line(data);
	if (g_signal != READ_MODE)
		data->exit_status = g_signal;
	if (line == NULL)
	{
		if (errno == ENOMEM)
			data->exit_status = ENOMEM;
		else
			printf("exit\n");
		exitshell(NULL, data);
	}
	g_signal = EXECUTE_MODE;
	detect_line(line, data);
	args = ;
	free(line);
	free(args);
}

int	main(int argc, char **argv, char **env)
{
	t_shell_data	*data;
	int				i;

	data = initialize(argc, argv, env);
	if (data == NULL)
		return (EXIT_FAILURE);
	if (ac >= 2)
	{
		i = 1;
		while (1 < argc)
		{
			detect_line(argv[1], data);
			i++;
		}
	}
	lsh_loop(data);
}
