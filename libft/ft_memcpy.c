/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:28:11 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/02/27 16:53:06 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*dest_ptr;

	dest_ptr = dest;
	if (!dest && !src)
		return (dest);
	while (n--)
	{
		*(char *)dest = *(char *)src;
		dest++;
		src++;
	}
	return (dest_ptr);
}

// int	main(void)
// {
// 	char	src[] = "Hello, world!";
// 	char	src1[] = "Jello, world!";
// 	char	dest[20];
// 	char	dest1[20];

// 	// Copy the content of src to dest
// 	memcpy(dest, src, strlen(src) + 1);
// 	ft_memcpy(dest1, src1, strlen(src1) + 1);
// 	// Print the copied string
// 	printf("Copied string: %s\n", dest);
// 	printf("Copied string2: %s\n", dest1);
// 	return (0);
// }
