/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testhead.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselbay1 <tanselbay1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:07:25 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/02 21:05:02 by tanselbay1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stddef.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <readline/history.h>
# include <readline/readline.h>


// ANSI Color codes for terminal output formatting:
// Y - Yellow
// G - Green
// C - Cyan
// RED - Red
// RST - Reset to default color

#define Y "\033[1;33m"
#define G "\033[1;32m"
#define C "\033[1;36m"
#define RED "\033[1;31m"
#define RST "\033[0m"
typedef struct s_pipseq
{
	char			*in_file;
	char			*out_file;
	char			*command;
	int				fd_in;
	int				fd_out;
	struct s_pipseq	*next;
}					t_pipseq;

typedef struct s_tokens
{
	int			squote;
	int			dquote;
	int			dollar;
	int			pipe;
	int			redir;
	int			outfil;
	int			herdoc;
	int			append;
}					t_tokens;

char	*read_line(void);
void	lsh_loop(void);

#endif