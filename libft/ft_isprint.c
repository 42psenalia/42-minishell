/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:03:43 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/03/07 15:24:11 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int isPrint;
// 	int isPrintOrg;

// 	isPrint = ft_isprint(33);
// 	isPrintOrg = isprint(33);
// 	printf("Is there any printable character? %d\n", isPrint);
// 	printf("Is there any printable character? %d\n", isPrintOrg);
// 	return (0);
// }