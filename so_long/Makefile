NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror
LIBMLX	:= ./lib/mlx42
LIBFT	:= ./lib/libft

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/libft.h
LIBS	:= $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a -ldl -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm 
SRCS	:= src/bones.c \
			src/images.c \
			src/main.c \
			src/map_validator_extras.c \
			src/map_validator.c \
			src/map.c \
			src/move.c 
OBJS	:= ${SRCS:.c=.o}

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@make clean -C $(LIBFT)
	@rm -rf $(OBJS)
	@find $(LIBMLX)/build -type f ! -name '*.a' -delete
	@find $(LIBMLX)/build -type d -empty -delete
	@printf "$(NAME) Cleaned Successfully!\n"

fclean: clean
		@rm -rf $(LIBFT)/libft.a
		@rm -rf $(NAME)
		@rm -rf $(LIBMLX)/build

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft
