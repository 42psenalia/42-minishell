NAME := libft.a

CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -rf
AR := ar rcs

HEADERS := libft.h
SRCS := 
OBJS := $(SRCS:%.c=%.o)

all: $(NAME)

clean:
	@echo "delete libft's .o files"
	@$(RM) $(OBJS)

fclean: clean
	@echo "delete libft.a"
	@$(RM) $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
