/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:50:18 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/03/09 10:06:00 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int isAlpha;
// 	int isAlphaOrg;

// 	isAlpha = ft_isalpha(97);
// 	isAlphaOrg = isalpha(97);
// 	printf("Is there any alfabetical char? %d\n", isAlpha);
// 	printf("Is there any alfabetical char? %d\n", isAlphaOrg);
// 	return (0);
// }