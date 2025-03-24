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

static void	free_n_items(char **arr, size_t n)
{
	size_t	i;

	printf("normal free\n");
	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
}

static void	free_till_null(char **arr)
{
	printf("no size free\n");
	while (*arr)
	{
		free(*arr);
		arr++;
	}
}


void	free_strarray(char **array, size_t n)
{
	printf("array %p ", array);
	// {
	// 	printf("normal free\n");
	// 	i = 0;
	// 	while (i < n)
	// 	{
	// 		free(array[i]);
	// 		i++;
	// 	}
	// }
	// else
	// {
	// 	printf("no size free\n");
	// 	while (*array)
	// 	{
	// 		printf("array %s", *array);
	// 		free(*array);
	// 		printf(" freed\n");
	// 		array++;
	// 	}
	// }
	if (n > 0)
		free_n_items(array, n);
	else
		free_till_null(array);
	printf("all array contents freed\n");
	free(array);
	printf("free strarray done\n");
}
