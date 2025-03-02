# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 16:49:15 by tanselbayra       #+#    #+#              #
#    Updated: 2024/03/07 14:42:15 by tbayrakt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######### Variables ########
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
NAME = libft.a
AR = ar rcs
LIB = ranlib

SRCS = ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o \
	ft_isdigit.o ft_isprint.o ft_memset.o ft_strlen.o \
	ft_toupper.o ft_tolower.o ft_memcpy.o ft_memmove.o \
	ft_strlcpy.o ft_strlcat.o ft_strchr.o ft_strrchr.o \
	ft_strncmp.o ft_strnstr.o ft_memchr.o ft_memcmp.o \
	ft_atoi.o ft_calloc.o ft_strdup.o ft_substr.o \
	ft_strjoin.o ft_strtrim.o ft_split.o ft_itoa.o \
	ft_strmapi.o ft_striteri.o ft_putchar_fd.o ft_putstr_fd.o \
	ft_putendl_fd.o ft_putnbr_fd.o

OBJS = ${SRCS:.c=.o}

######### Targets ########
all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}
	${LIB} ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

######### Clean ########
# Clean obj files (.o)
clean:
	${RM} ${OBJS}

# Clean obj and library (.o .a)
fclean: clean
	${RM} ${NAME}

# Re-Make the library
re: fclean all

# Dependency of header file for all obj
${OBJS}: libft.h

.PHONY: all clean fclean re