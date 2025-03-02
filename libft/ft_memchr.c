/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:45:59 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/03/09 09:03:05 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s = (unsigned char *)s + 1;
	}
	return (NULL);
}
// int	main(void)
// {
// 	char str[] = "Hello, World!";
// 	char *result;

// 	// Test case 1: Search for 'o' in the string
// 	result = ft_memchr(str, 'o', strlen(str));
// 	printf("Test Case 1: Search for 'o'\n");
// 	if (result != NULL)
// 		printf("Character 'o' found at position: %ld\n", result - str);
// 	else
// 		printf("Character 'o' not found\n");

// 	// Test case 2: Search for 'x' which is not in the string
// 	result = ft_memchr(str, 'x', strlen(str));
// 	printf("\nTest Case 2: Search for 'x'\n");
// 	if (result != NULL)
// 		printf("Character 'x' found at position: %ld\n", result - str);
// 	else
// 		printf("Character 'x' not found\n");

// 	// Test case 3: Search for '\0' (null terminator)
// 	result = ft_memchr(str, '\0', strlen(str));
// 	printf("\nTest Case 3: Search for '\\0'\n");
// 	if (result != NULL)
// 		printf("Null terminator found at position: %ld\n", result - str);
// 	else
// 		printf("Null terminator not found\n");

// 	return (0);
// }