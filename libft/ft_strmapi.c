/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:23:12 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/03/07 11:23:20 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>
// #include <stdlib.h>

// char	my_function(unsigned int index, char c)
// {
// 	(void)index;
// 	// Example transformation: convert lowercase characters to uppercase
// 	if (c >= 'a' && c <= 'z')
// 		return (c - 'a' + 'A'); // convert to uppercase
// 	else
// 		return (c); // return unchanged
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*result;
	size_t	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	return (result);
}

// int	main(void)
// {
// 	char input[] = "Hello, World!";
// 	char *result = ft_strmapi(input, my_function);
// 	printf("Result: %s\n", result);
// 	free(result); // Don't forget to free the memory allocated by ft_strmapi
// 	return (0);
// }