#include "parser.h"

char	*ft_getcwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path == NULL)
	{
		perror("getcwd failed");
		// Provide a fallback value if getcwd fails
		path = ft_strdup("(unknown)");
		if (!path)
		{
			fprintf(stderr, "Error: Memory allocation failed in ft_getcwd\n");
			exit(EXIT_FAILURE);
		}
	}
	return (path);
}

int	is_special(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == '\'' || c == '"');
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' \
		|| c == '\f' || c == '\r');
}
