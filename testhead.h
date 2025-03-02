/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testhead.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselbay1 <tanselbay1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:07:25 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/02 13:25:33 by tanselbay1       ###   ########.fr       */
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