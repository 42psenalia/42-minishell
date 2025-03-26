#include "execute.h"

void	handle_dollar(char *darg, t_shell_data *data)
{
	t_envar_list	*list;
	t_envar			*env;

	printf("$var found\n");
	if (darg[0] != '$')
		return ;
	printf("not failed\n");
	if (ft_strcmp(darg, "$?") == 0)
		ft_putnbr_fd(data->exit_status, 1);
	else
	{
		printf("not $?\n");
		list = data->envar_list;
		while(list)
		{
			env = list->content;
			if (ft_strcmp(darg + 1, env->key) == 0)
			{
				printf("%s", env->value);
				return ;
			}
			list = list->next;
		}
	}
}
