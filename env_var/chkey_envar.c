#include "envar.h"

bool	envar_keychk(char *key)
{
	if (!(ft_isalpha(*key) || *key == '_'))
		return (false);
	key++;
	while (*key)
	{
		if (!(ft_isalnum(*key) || *key == '_'))
			return (false);
		key++;
	}
	return (true);
}
