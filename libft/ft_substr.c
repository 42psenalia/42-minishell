/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:54:36 by tanselbayra       #+#    #+#             */
/*   Updated: 2024/03/08 12:01:28 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substring;
	size_t	end;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	end = start + len;
	if (end > s_len)
		end = s_len;
	substring = malloc(end - start + 1);
	if (!substring)
		return (NULL);
	ft_strlcpy(substring, s + start, end - start + 1);
	return (substring);
}

// Line 25: Handle start beyond string length
// Line 28: Adjust end if exceeding string length
// Line 32: Copy characters

// #include <stdlib.h>
// #include <stdio.h>

// int main()
// {
//    const char *s = "Hello, World!";
//    unsigned int start = 4;
//    size_t len = 7;

//    char *substr = ft_substr(s, start, len);

//    if (!substr)
//       printf("Substring is NULL\n");
//    else
//       printf("Substring: %s\n", substr);

//    free(substr);

//    return (0);
// }