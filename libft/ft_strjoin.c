/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:31:49 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/03/08 11:23:45 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_ptr;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	str_ptr = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!str_ptr)
		return (NULL);
	ft_strlcpy(str_ptr, s1, total_len + 1);
	ft_strlcat(str_ptr, s2, total_len + 1);
	return (str_ptr);
}

// Line 17: Pointer to the concatenated string
// Line 18: Total length of the concat str
// Line 25: Copy the contents of s1 into the allocated memory
// Line 26: Concatenate the contents of s2 to the end of str_ptr

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Prototype of ft_strjoin function
// char	*ft_strjoin(char const *s1, char const *s2);

// // Function to compare two strings and print result
// void	test(char const *s1, char const *s2, char const *expected_result)
// {
// 	char	*result;

// 	result = ft_strjoin(s1, s2);
// 	if (strcmp(result, expected_result) == 0)
// 	{
// 		printf("Test passed: \"%s\" + \"%s\" = \"%s\"\n", s1, s2,
// 			expected_result);
// 	}
// 	else
// 	{
// 		printf("Test failed: \"%s\" + \"%s\" expected \"%s\" but got \"%s\"\n",
// 			s1, s2, expected_result, result);
// 	}
// 	free(result);
// }

// int	main(void)
// {
// 	// Test cases
// 	test("Hello", "World", "HelloWorld");
// 	test("", "World", "World");
// 	test("Hello", "", "Hello");
// 	test(NULL, "World", NULL);
// 	test("Hello", NULL, NULL);
// 	test(NULL, NULL, NULL);
// 	return (0);
// }
