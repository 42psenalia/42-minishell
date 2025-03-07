#include "libft.h"
#include <stdio.h>

bool	parent_builtin(char *name)
{
	if (!name)
		return (false);
	if (ft_strsmp(name, "cd") == 0 || ft_strcmp(name, "exit") == 0 ||
		ft_strcmp(name, "export") == 0 || ft_strcmp(name, "unset") == 0)
		return (true);
	return (false);
}

bool	builtin_check(char *name)
{
	if (!name)
		return (false);
	if (parent_builtin(name) || ft_strcmp(name, "env") == 0 ||
		ft_strcmp(name, "pwd") == 0 || ft_strcmp(name, "echo") == 0)
		return (true);
	return (false);
}
