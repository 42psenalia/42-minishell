/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:26:03 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/03/09 09:12:20 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			total_size;
	unsigned char	*tmp;

	if (count != 0 && size != 0 && count > (UINT_MAX / size))
		return (NULL);
	total_size = count * size;
	tmp = (unsigned char *)malloc(total_size);
	if (tmp == NULL)
		return (NULL);
	ft_bzero(tmp, total_size);
	return (tmp);
}
// Line 20: Check for potential overflow or invalid arguments
// Line 22: Calculate the total size to allocate
// Line 26: If successfull, initialize the allocated memory to zero
// Line 27: Return the pointer to the allocated memory

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	int	*array1;
// 	int	*array2;

// 	// Test case 1: Allocate memory for an array of 5 integers
// 	array1 = (int *)ft_calloc(5, sizeof(int));
// 	if (array1 == NULL)
// 	{
// 		printf("Memory allocation failed for test case 1\n");
// 		return (1); // Return error code
// 	}
// 	// Print the elements of the array (should be initialized to zero)
// 	printf("Test case 1: Array elements (initialized to zero):\n");
// 	for (int i = 0; i < 5; i++)
// 	{
// 		printf("%d ", array1[i]);
// 	}
// 	printf("\n");
// 	// Free the allocated memory
// 	free(array1);
// 	// Test case 2: Allocate memory for an array of 0
// 	// elements (should return NULL)
// 	array2 = (int *)ft_calloc(0, sizeof(int));
// 	if (array2 != NULL)
// 	{
// 		printf("Test case 2 failed: Memory allocation
// 		should return (NULL\n");
// 		return (1); // Return error code
// 	}
// 	printf("Test case 2: Memory allocation
// 	returned NULL (as expected)\n");
// 	return (0); // All test cases passed
// }
