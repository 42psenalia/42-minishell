/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:52:19 by tanselbay1        #+#    #+#             */
/*   Updated: 2025/03/29 14:34:15 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_signal;

static void	detect_line(char *line, t_shell_data *data)
{
	t_command	*commands;
	int			progress;

	if (ft_strlen(line) == 0)
	{
		data->exit_status = SUCCESS;
		return ;
	}
	commands = NULL;
	progress = parser(line, &commands, data);
	if (progress == EINVAL || commands == NULL)
	{
		printf("error: no entry found\n");
		data->exit_status = ENOENT;
		return ;
	}
	else if (progress == ENOMEM)
		builtin_exit(NULL, data);
	printf("entering execution\n----------------\n");
	data->exit_status = main_execute(&commands, data);
}

static void	lsh_loop(t_shell_data *data)
{
	char		*line;

	while (TRUE)
	{
		g_signal = READMODE;
		line = read_line();
		if (g_signal != READMODE)
			data->exit_status = g_signal;
		if (line == NULL)
		{
			if (errno == ENOMEM)
				data->exit_status = ENOMEM;
			else
				printf("exit\n");
			builtin_exit(NULL, data);
		}
		g_signal = EXECUTEMODE;
		detect_line(line, data);
		free(line);
	}
}

int	main(int ac, char **av, char **env)
{
	t_shell_data	*data;
	int				i;

	setup_signal();
	data = initialize(ac, av, env);
	if (data == NULL)
		return (EXIT_FAILURE);
	(void)av;
	if (ac >= 1)
		printf(Y"Welcome to the 42bash!\n"RST);
	if (ac >= 2)
	{
		i = 1;
		while (i < ac)
		{
			detect_line(av[i], data);
			i++;
		}
	}
	lsh_loop(data);
}
