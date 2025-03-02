/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:00:02 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/02/29 09:44:53 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (*str != '\0')
	{
		counter++;
		str++;
	}
	return (counter);
}
// int	main(void)
// {
// 	char word[10] = "somethinng";

// 	printf("Length of word is: %zu\n", ft_strlen(word));
// 	printf("Length of word in original function is: %lu\n", strlen(word));
// 	return (0);
// }