/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:59:12 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 12:59:12 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	parent_builtin(char *name)
{
	if (!name)
		return (0);
	return (ft_strcmp(name, "cd") == 0 || ft_strcmp(name, "exit") == 0 || \
		ft_strcmp(name, "export") == 0 || ft_strcmp(name, "unset") == 0);
}

int	builtin_check(char *name)
{
	if (!name)
		return (0);
	return (parent_builtin(name) || ft_strcmp(name, "env") == 0 || \
		ft_strcmp(name, "pwd") == 0 || ft_strcmp(name, "echo") == 0);
}
