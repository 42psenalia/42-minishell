/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:44:29 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/03/07 12:03:18 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
// #include <stdio.h>

// void	print_index_and_char(unsigned int index, char *c)
// {
// 	printf("Index: %u, Char: %c\n", index, *c);
// }

// int	main(void)
// {
// 	char str[] = "Hello, world!";

// 	// Testing ft_striteri
// 	printf("Original string: %s\n", str);
// 	ft_striteri(str, &print_index_and_char);

// 	return (0);
// }