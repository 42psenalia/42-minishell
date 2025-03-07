#ifndef PARSE_LINE_H
# define PARSE_LINE_H

# include "../setup/shell_data.h"

int	parse_line(char *line, t_shell_data *data, t_command_list **commands);

#endif
