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
	t_execute	*exe_cmd;
	t_list		*redirs;
	t_tokens	*file;
	t_tokens	*operator;

	while (cmd_lst)
	{
		exe_cmd = cmd_lst->content;
		if (exe_cmd->command->redirs)
		{
			redirs = exe_cmd->command->redirs;
			while (redirs)
			{
				operator = redirs->content;
				if (operator->type == HEREDOC)
				{
					redirs = redirs->next;
					file = redirs->content;
					exe_cmd->fd_heredoc = get_inputs(file->str);
				}
				redirs = redirs->next;
			}
		}
		cmd_lst = cmd_lst->next;
	}
}
