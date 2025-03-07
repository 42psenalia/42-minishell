#ifndef SHELLSTART_H
# define SHELLSTART_H

# include "envar.h"
# include "libft.h"

# define READMODE 0
# define EXECUTEMODE -1

typedef struct s_shell_data
{
    t_exit_status   exit_status;
    t_envar_list    *envar_list;
}   t_shell_data;


t_shell_data    *initialize(int argc, char **argv, char **env);
void	        silent_cntl(void);
void	        restore_terminal_settings(void);
void	        setup_signal(void);

#endif
