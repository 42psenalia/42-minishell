/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:57:35 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/02/27 18:06:13 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>
// #include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*dest_ptr;

	dest_ptr = dest;
	if (!dest && !src)
		return (dest);
	if (dest == src)
		return (dest);
	if (dest > src)
	{
		while (n--)
			((char *)dest)[n] = ((char *)src)[n];
	}
	else
	{
		while (n--)
			*(char *)dest++ = *(char *)src++;
	}
	return (dest_ptr);
}

// int	main(void)
// {
// 	char	str[] = "Hello, world!";
// 	char	buffer[20];
// 	char	str1[] = "Jello, hoho!";
// 	char	buffer1[20];

// 	// Copy the content of str to buffer
// 	memmove(buffer, str, strlen(str) + 1);
// 	ft_memmove(buffer1, str1, strlen(str1) + 1);
// 	// Print the copied string
// 	printf("Copied string: %s\n", buffer);
// 	printf("Copied string1: %s\n", buffer1);
// 	// Move "world!" to the beginning of the buffer
// 	memmove(buffer, buffer + 7, 6);
// 	ft_memmove(buffer1, buffer1 + 7, 4);
// 	// Print the modified string
// 	printf("Modified string: %s\n", buffer);
// 	printf("Modified string1: %s\n", buffer1);
// 	return (0);
// }
