/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:58:08 by tbayrakt          #+#    #+#             */
/*   Updated: 2025/04/02 14:42:54 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*ft_getcwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path == NULL)
	{
		perror("getcwd failed");
		path = ft_strdup("(unknown)");
		if (!path)
		{
			ft_putstr_fd("Error: getcwd failed to allocate\n", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
	}
	return (path);
}

int	is_special(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == '\'' || c == '"');
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}
