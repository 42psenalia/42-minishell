/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peterpiper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:13:48 by psenalia          #+#    #+#             */
/*   Updated: 2024/12/19 17:52:39 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testhead.h"

bool	assign_fds(t_pipseq *block, int size)
{
	int	piper[2];

	while (block->next)
	{
		if (pipe(piper) < 0)
		{
			perror("pipe: pipe failed");
			return (false);
		}
		block->fd_in = piper[0];
		block->fd_out = piper[1];
		block = block->next;
	}
	return (true);
}

t_pipseq	*find_latest(t_pipseq *block)
{
	if (!block)
		return (NULL);
	while (block->next)
		block = block->next;
	return (block);
}

void	clearblock(t_pipseq **block)
{
	t_pipseq	*temp;

	if (block && *block)
	{
		while (*block)
		{
			temp = (*block)->next;
			if ((*block)->fd_in)
				close((*block)->fd_in);
			if ((*block)->fd_out)
				close((*block)->fd_out);
			if ((*block)->pipid)
				free((*block)->pipid);
			free(*block);
			*block = temp;
		}
		block = NULL;
	}
}

static t_pipseq	*setblocks(t_pipseq **block, int pipen)
{
	t_pipseq	*temp;
	int			n;

	n = 0;
	while (n < pipen)
	{
		temp = malloc(sizeof(t_pipseq));
		if (!temp)
		{
			clearblock(block);
			return (NULL);
		}
		ft_bzero(temp, sizeof(t_pipseq));
		if (!*block)
			*block = temp;
		else
			find_latest(*block)->next = temp;
	}
}

void	pipezo(int n)
{
	t_pipseq	*block;

	block = NULL;
	block = setblocks(&block, n);
	if (!assign_fds(block, n))
		return (perror("pipe"));
}
