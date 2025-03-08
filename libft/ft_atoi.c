/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:21:15 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/03/09 09:45:05 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	i;
	int	sign;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
// Line 24: Skip leading whitespace
// Line 27: Check for sign
// Line 29: Ensure returning correct sign, if sign is minus (*
// -1 make it negative n)
// Line 34: Convert digit to integer

// #include <stdio.h>

// // Test function
// void	test_ft_atoi(const char *str)
// {
// 	int	num;

// 	printf("String: \"%s\"\n", str);
// 	num = ft_atoi(str);
// 	printf("Converted integer: %d\n", num);
// 	printf("-----------------------------------\n");
// }

// int	main(void)
// {
// 	// Test cases
// 	test_ft_atoi("12345");     // Positive number
// 	test_ft_atoi("-6789");     // Negative number
// 	test_ft_atoi("0");         // Zero
// 	test_ft_atoi("  42");      // Leading whitespace
// 	test_ft_atoi("   -999");   // Leading whitespace and negative sign
// 	test_ft_atoi("abc123");    // Non-numeric characters after numeric
// 	test_ft_atoi("123abc");    // Non-numeric characters before numeric
// 	test_ft_atoi("  +789xyz"); // Leading whitespace, positive sign,
// 	// and non-numeric characters
// 	test_ft_atoi("2147483647");  // Maximum positive value (INT_MAX)
// 	test_ft_atoi("-2147483648"); // Minimum negative value (INT_MIN)
// 	return (0);
// }
