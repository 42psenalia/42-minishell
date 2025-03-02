/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:47:02 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/02/21 14:22:39 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int arg)
{
	if (arg > 47 && arg < 58)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int isDigit;
// 	int isDigitOrg;

// 	isDigit = ft_isdigit('+');
// 	isDigitOrg = isdigit('+');
// 	printf("Is there any digit? %d\n", isDigit);
// 	printf("Is there any digit? %d\n", isDigitOrg);
// 	return (0);
// }