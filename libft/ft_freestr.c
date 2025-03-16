/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:01:18 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 13:01:18 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_strarray(char **array, size_t n)
{
	size_t	i;

	if (n > 0)
	{
		i = 0;
		while (i < n)
		{
			free(array[i]);
			i++;
		}
	}
	else
	{
		while (*array)
		{
			free(*array);
			array++;
		}
	}
	free(array);
}
