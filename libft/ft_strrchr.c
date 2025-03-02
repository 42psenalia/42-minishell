/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:47:20 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/03/09 09:15:09 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>
//#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	chrc;
	int		back_counter;

	chrc = (char)c;
	back_counter = ft_strlen(s);
	while (back_counter >= 0)
	{
		if (s[back_counter] == chrc)
			return ((char *)s + back_counter);
		back_counter--;
	}
	return (NULL);
}

// Line 24: Find the length of string to loop back
// Line 25: Loop through to find matching

// int	main(void)
// {
// 	char	test[] = "Hello";
// 	char	*result;

// 	result = ft_strrchr(test, 'o');
// 	if (result != NULL)
// 		printf("Character 'o' found at position: %ld\n", result - test);
// 	else
// 		printf("Character not found\n");
// 	return (0);
// }