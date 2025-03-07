#include "../libft/libft.h"
#include "builtin.h"

t_exit_status	builtin_unset(int argc, char *argv, t_shell_data *data)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		delete_envar(argv[i], &data->envar_list);
		i++;
	}
	return (SUCCESS);
}
