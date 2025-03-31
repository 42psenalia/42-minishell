/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:07:25 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/31 12:57:13 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "builtin/builtin.h"
# include "envar/envar.h"
# include "execute/execute.h"
# include "libft/libft.h"
# include "parser/parser.h"
# include "shellstart.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>

// ANSI Color codes for terminal output formatting:
// Y - Yellow
// G - Green
// C - Cyan
// RED - Red
// RST - Reset to default color

# define Y "\033[1;33m"
# define G "\033[1;32m"
# define C "\033[1;36m"
# define RED "\033[1;31m"
# define RST "\033[0m"

// MAIN.C
int	main(int ac, char **av, char **env);

// --SIGNALS--
// SIGNAL_BUTTONS.C
// void	setup_signal(void);

#endif