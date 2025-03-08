/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:27:25 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/03/08 11:20:47 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	int		len;
	char	*trimmed;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	len = end - start + 1;
	trimmed = (char *)malloc((len) * sizeof(char));
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, len);
	return (trimmed);
}
// Line 24: Find the start of the str without set characters
// Line 26: Find the end of the str without set characters
// Line 29: Allocate memory for the trimmed str

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	const char *s1[] = {"  hello world  ", "", "abcde", "hello", "---hello---",
// 		"-----", "ab-cd-ef", "----abcd", "abcd----", "a--b-cd--e-f--"};
// 	const char *set[] = {" ", " ", "abcde", "xyz", "-", "-", "-", "-", "-",
// 		"-"};

// 	int num_tests = sizeof(s1) / sizeof(s1[0]);

// 	for (int i = 0; i < num_tests; ++i)
// 	{
// 		char *result = ft_strtrim(s1[i], set[i]);
// 		printf("Test %d: Original: \"%s\", Set: \"%s\", Result: \"%s\"\n", i
// 			+ 1, s1[i], set[i], result);
// 		free(result);

// 		return (0);
// 	}