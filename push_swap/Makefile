# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 21:54:57 by prayo-ga          #+#    #+#              #
#    Updated: 2024/05/15 21:54:57 by prayo-ga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wextra -Wall -Werror 
LIBFT = ./libft

HEADERS := -I ./includes -I $(LIBFT)/libft.h
SRCS = ./src/algorithm.c\
	./src/checker.c\
	./src/cost.c\
	./src/main.c\
	./src/movements.c\
	./src/position.c\
	./src/push.c\
	./src/reverse_rotate.c\
	./src/rotate.c\
	./src/stack.c\
	./src/swap.c\
	./src/utils.c\

CC = gcc

OBJS = ${SRCS:.c=.o}

all: $(LIBFT)/libft.a $(NAME)
	
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(LIBFT)/libft.a $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

clean:
	@rm -rf $(OBJS)
	@make -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re bonus