#include "../parser.h"

char	*ft_getcwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path == NULL)
		return (NULL);
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
