NAME = push_swap
NAME_BONUS = checker
CFLAGS = -Wextra -Wall -Werror
LIBFT = ./libft
SRC = src/\
		src/\
		src/\
		src/\
		src/\
		src/\
		src/\
		src/\
		src/\
		src/\
		src/\
		src/\

SRC_BONUS = src/\
			src/\
			src/\
			src/\
			src/\
			src/\
			src/\
			src/\
			src/\
			src/\
			src/\
			src/\
			src/\

CC = gcc
OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)
all: $(LIBFT)/libft.a $(NAME)
bonus: $(LIBFT)/libft.a $(NAME_BONUS)
$(NAME): $(OBJS)
		@$(CC) -g $(CFLAGS) $(LIBFT)/libft.a $(OBJS_BONUS) -o $(NAME_BONUS)
%.o: %.c
		@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && "Compiling: $(notdir $<)\n"
$(LIBFT)/libft.a:
		@make -C $(LIBFT)
clean:
		@rm -rf $(OBJS) $(OBJS_BONUS)
		@make -C $(LIBFT) clean
fclean: clean
		@rm -rf $(NAME) $(NAME_BONUS)
		@make -C $(LIBFT) fclean
re: fclean all
.PHONY: all clean fclean re bonus