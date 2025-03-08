/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:21:36 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/02/29 18:05:02 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = s1;
	str2 = s2;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}
// #include <stdio.h>
// #include <string.h>

// int	ft_memcmp(const void *s1, const void *s2, size_t n);

// int	main(void)
// {
// 	char	str1[] = "Hello";
// 	char	str2[] = "Hello";
// 	int		result1;
// 	char	str3[] = "Hello";
// 	char	str4[] = "World";
// 	int		result2;
// 	char	str5[] = "Hello";
// 	char	str6[] = "Hell";
// 	int		result3;

// 	// Test case 1: Equal memory blocks
// 	result1 = ft_memcmp(str1, str2, strlen(str1));
// 	printf("Test case 1: Result = %d\n", result1); // Expected output: 0 (equal)
// 	// Test case 2: Different memory blocks
// 	result2 = ft_memcmp(str3, str4, strlen(str3));
// 	printf("Test case 2: Result = %d\n", result2);
// 		// Expected output: non-zero (different)
// 	// Test case 3: Partially equal memory blocks
// 	result3 = ft_memcmp(str5, str6, strlen(str5));
// 	printf("Test case 3: Result = %d\n", result3);
// 		// Expected output: non-zero (different)
// 	return (0);
// }
