/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:05:34 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/03/09 10:19:18 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// if (s1[i] == '\0' || s2[i] == '\0')
// 	return (s1[i] - s2[i]);

// Line 19: Initialize index counter
// Line 20: Loop through the strings and compare up to n characters
// Line 24: If characters are different, return their difference
// Line 28: If all characters are equal, return 0

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	str1[] = "Hello";
// 	char	str2[] = "Hello, World";

// 	int result = ft_strncmp(str1, str2, 3); // Compare first 3 characters
// 	if (result == 0)
// 		printf("The first 3 characters of str1 and str2 are equal.\n");
// 	else if (result < 0)
// 		printf("The first 3 characters of str1 are less than str2.\n");
// 	else
// 		printf("The first 3 characters of str1 are greater than str2.\n");
// 	return (0);
// }
