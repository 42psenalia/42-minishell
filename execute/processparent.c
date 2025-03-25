/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processparent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:00:56 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 13:00:56 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	ft_parentprocess(t_list *cmd_lst, int *prev_fd, t_execute *cmd)
{
	// printf("parenting process\n");
	if (cmd_lst->next)
	{
		close(cmd->pipe_fds[1]);
		if (*prev_fd != -1)
			close(*prev_fd);
		*prev_fd = cmd->pipe_fds[0];
	}
	else if (*prev_fd != -1)
		close(*prev_fd);
	// printf("parenting finished\n");
}
