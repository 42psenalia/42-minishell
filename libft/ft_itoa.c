/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:53:37 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/03/08 10:37:09 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function to count the number of digits in an integer
int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*c;
	unsigned int	len;
	unsigned int	num;

	len = count_digits(n);
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (c == NULL)
		return (NULL);
	num = n;
	if (n < 0)
	{
		c[0] = '-';
		num = -n;
	}
	if (num == 0)
		c[0] = '0';
	c[len] = '\0';
	while (num != 0)
	{
		c[len - 1] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (c);
}
