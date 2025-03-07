#include "../libft/libft.h"
#include "builtin.h"

t_exit_status	builtin_env(int argc, char **argv, t_shell_data *data)
{
	(void) argc;
	(void) argv;
	print_envar_list(data->env_var_list);
	return (SUCCESS);
}
