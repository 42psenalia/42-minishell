/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:51:21 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/02/21 16:36:14 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	chr;

	ptr = (unsigned char *)str;
	chr = (unsigned char)c;
	while (n--)
		*ptr++ = chr;
	return (str);
}

// int	main(void)
// {
// 	char str[40];

// 	strcpy(str, "This is string.h library function");
// 	puts(str);

// 	memset(str, '$', 7);
// 	puts(str);

// 	ft_memset(str, '#', 10);
// 	puts(str);

// 	return (0);
// }