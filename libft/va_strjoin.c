/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:02:01 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 13:02:01 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdarg.h"

static size_t	countlen(int n, va_list inhargs)
{
	va_list	args;
	size_t	len;
	int		i;
	char	*str;

	va_copy(args, inhargs);
	len = 0;
	i = 0;
	while (i < n)
	{
		str = va_arg(args, char *);
		if (!str)
			return (0);
		len += ft_strlen(str);
		i++;
	}
	va_end(args);
	return (len);
}

static void	addup(int n, va_list args, char *joined)
{
	int		i;
	int		j;
	char	*str;
	size_t	len;

	i = 0;
	j = 0;
	while (i < n)
	{
		str = va_arg(args, char *);
		len = ft_strlen(str);
		ft_memcpy(joined + j * sizeof(char), str, len);
		i++;
		j += len;
	}
	joined[j] = '\0';
	va_end(args);
}

char	*va_strjoin(int n, ...)
{
	va_list	args;
	size_t	len;
	char	*joined;

	va_start(args, n);
	len = countlen(n, args);
	joined = malloc((len + 1) * sizeof(char));
	if (joined == NULL)
	{
		va_end(args);
		return (NULL);
	}
	addup(n, args, joined);
	return (joined);
}
