/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:35:41 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/02/21 14:22:49 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int arg)
{
	if ((arg > 64 && arg < 91) || (arg > 96 && arg < 123))
		return (1);
	if (arg > 47 && arg < 58)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int isAlDigit;
// 	int isAlDigitOrg;

// 	isAlDigit = ft_isalnum(' ');
// 	isAlDigitOrg = isalnum(' ');
// 	printf("Is there any digit or alphabet? %d\n", isAlDigit);
// 	printf("Is there any digit or alphabet? %d\n", isAlDigitOrg);
// 	return (0);
// }