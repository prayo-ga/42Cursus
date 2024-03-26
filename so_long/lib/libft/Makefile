# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 16:37:50 by prayo-ga          #+#    #+#              #
#    Updated: 2024/03/25 17:46:46 by prayo-ga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS            =   ft_bzero.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_memcpy.c \
					ft_memset.c \
					ft_strlen.c \
					ft_memmove.c \
					ft_strlcpy.c \
					ft_strlcat.c \
					ft_toupper.c \
					ft_tolower.c \
					ft_strchr.c \
					ft_strncmp.c \
					ft_memchr.c \
					ft_strrchr.c \
					ft_memcmp.c \
					ft_strnstr.c \
					ft_calloc.c \
					ft_strdup.c \
					ft_atoi.c \
					ft_substr.c \
					ft_strjoin.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_itoa.c \
					ft_strtrim.c \
					ft_split.c \
					ft_striteri.c \
					ft_strmapi.c \
					ft_printf.c \
					ft_printf_print.c \
					ft_aux.c



OBJS            = $(SRCS:.c=.o)

CC              = @gcc

RM              = @rm -f

CFLAGS          = -Wall -Wextra -Werror -I.

NAME            = libft.a

all:            $(NAME)

$(NAME):        $(OBJS)
				@ar rcs $(NAME) $(OBJS)
				@printf "Libft Compiled Successfully!\n"

clean:
				$(RM) $(OBJS)
				@printf "Libft Cleaned!\n"

fclean:         clean
				$(RM) $(NAME)
				@printf "Libft Fully Cleaned!\n"

re:				fclean $(NAME)
				@printf "Libft Remaked!\n"

.PHONY:			all clean fclean re
