/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:01:03 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 13:01:03 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "readline/readline.h"

static int	get_inputs(char *delimiter)
{
	int		pipe_fd[2];
	char	*line;

	if (pipe(pipe_fd) == -1)
	{
		perror("pipe failed");
		return (-1);
	}
	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			break ;
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, pipe_fd[1]);
		free(line);
	}
	close(pipe_fd[1]);
	return (pipe_fd[0]);
}

void	run_heredocs(t_list *cmd_lst)
{
	t_execute		*exe_cmd;
	t_ast			*comms;
	char			*file;

	while (cmd_lst)
	{
		exe_cmd = cmd_lst->content;
		if (exe_cmd->command->token)
		{
			comms = exe_cmd->command;
			while (comms)
			{
				if (comms->token == HEREDOC)
				{
					comms = comms->next;
					file = comms->infile;
					exe_cmd->fd_heredoc = get_inputs(file);
				}
				comms = comms->next;
			}
		}
		cmd_lst = cmd_lst->next;
	}
}
