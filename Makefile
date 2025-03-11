# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 15:41:01 by psenalia          #+#    #+#              #
#    Updated: 2025/03/11 15:41:01 by psenalia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

MAKEFLAGS += --no-print-directory

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

OBJS_DIR = .objs

HEADERS = shellstart.h
SRCS = main.c readline.c shellstart.c setsig.c
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

MODULE_DIRS = parser execute builtin setup env_var
MODULES = $(foreach dir, $(MODULE_DIRS),$(dir)/$(dir).a)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

LFLAGS = -L/usr/include -lreadline -lhistory

.PHONY: all clean fclean re $(LIBFT_DIR) $(MODULE_DIRS)

all: $(LIBFT_DIR) $(MODULE_DIRS) $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@for dir in $(MODULE_DIRS); do \
		echo "clean $$dir"; \
		$(MAKE) clean -C $$dir; \
	done
	@echo "clean root directory";
	$(RM) $(OBJS_DIR)

fclean:
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@for dir in $(MODULE_DIRS); do \
		echo "fclean $$dir"; \
		$(MAKE) fclean -C $$dir; \
	done
	@echo "fclean root directory";
	$(RM) $(OBJS_DIR)
	$(RM) $(NAME)

re: fclean all

$(LIBFT_DIR) $(MODULE_DIRS):
	@echo "build $@"
	@$(MAKE) -C $@

$(LIBFT): $(LIBFT_DIR)
$(MODULES): $(MODULE_DIRS)

$(NAME): $(LIBFT) $(MODULES) $(OBJS)
	@echo "link minishell"
	$(CC) $(CFLAGS) $(OBJS) $(MODULES) $(LIBFT) $(LFLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: %.c $(HEADERS) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $@
