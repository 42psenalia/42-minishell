#include "execute.h"

static char	*find_value(char *dollar, t_shell_data *data)
{
	t_envar_list	*list;
	t_envar			*env;

	if (ft_strcmp(dollar, "$?") == 0)
	{
		// free(dollar);
		return (ft_itoa(data->exit_status));
	}
	printf("not $?\n");
	list = data->envar_list;
	while(list)
	{
		env = list->content;
		if (ft_strcmp(dollar + 1, env->key) == 0)
		{
			// free(dollar);
			return (env->value);
		}
		list = list->next;
	}
	// free(dollar);
	return (NULL);
}

char	*handle_dollar(char *darg, t_shell_data *data)
{
	char			*str;
	char			*dollar;
	char			*value;
	char			c;
	unsigned int	i;
	unsigned int	j;

	printf("$var found\n");
	i = 0;
	value = NULL;
	str = NULL;
	while (darg[i])
	{
		j = 0;
		if (darg[i] == '$')
		{
			if (i > 0)
				str = ft_substr(darg, j, i - j - 1);
			j = i;
			while (darg[i])
			{
				c = darg[++i];
				if (!ft_isalnum(c))
				{
					dollar = ft_substr(darg, j, i - j);
					break ;
				}
			}
			dollar = find_value(dollar, data);
			printf("replaced to %s\n", dollar);
			printf("joining %s %s %s\n", value, str, dollar);
			if (!value && !str)
				value = ft_substr(dollar, 0, sizeof(dollar));
			value = va_strjoin(3, value, str, dollar);
			printf("new str is %s\n", value);
			free(dollar);
			free(str);
			j = i;
		}
		i++;
	}
	str = ft_substr(darg, j, i - j - 1);
	value = ft_strjoin(value, str);
	if (!value)
		return (NULL);
	free (darg);
	return (value);
}
