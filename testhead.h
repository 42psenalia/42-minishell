/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testhead.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:07:25 by psenalia          #+#    #+#             */
/*   Updated: 2024/12/03 15:49:57 by psenalia         ###   ########.fr       */
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

#endif