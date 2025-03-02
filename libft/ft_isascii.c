/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:18:02 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/02/21 14:23:04 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int isAscii;
// 	int isAsciiOrg;

// 	isAscii = ft_isascii(-1);
// 	isAsciiOrg = isascii(-1);
// 	printf("Is there any ascii character? %d\n", isAscii);
// 	printf("Is there any ascii character? %d\n", isAsciiOrg);
// 	return (0);
// }