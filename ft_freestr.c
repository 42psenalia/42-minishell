#include "libft.h"

void	free_strarray(char **array,  size_t n)
{
	size_t	i;

	if (n > 0)
	{
		i = 0;
		while (i < n)
		{
			free(array[i]);
			i++;
		}
	}
	else
	{
		while (*array)
		{
			free(*array);
			array++;
		}
	}
	free(array);
}