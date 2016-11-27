# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/02 20:00:21 by hhismans          #+#    #+#              #
#    Updated: 2016/11/27 04:19:44 by hhismans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =	rt

SRC =	src/main.c			\
		src/hook.c			\
		src/init.c			\
		src/sphere.c		\
		src/vector.c		\
		src/objs.c		\

LIB =	-lft -L./libft\
		-lmlx -L./minilibx_macos\
		-I includes/ -I libft/ -I minilibx_macos\
		-framework OpenGL -framework Appkit -O3 -Ofast
DEL = rm -f

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(FLAG) -o $@ $(OBJ) $(LIB)
	@echo "\033[1;33mmake -> $@ created\033[1;37m"

%.o: %.c
	@gcc $(FLAG) -o $@ -c $< -I./libft -I ./includes
	@echo "\033[36mCompilation of\033[1m $< \033[32m done \033[37m"
clean:
	@make clean -C libft
	@$(DEL) $(OBJ)
	@echo "\033[0;33mclean -> .o deleted"

fclean: clean
	@make fclean -C libft
	@$(DEL) $(NAME)
	@echo "\033[1;31mfclean -> $(NAME) deleted\033[37m"

re: fclean all
	@make fclean -C libft
	@echo "\033[1;30mre -> $(NAME) reloaded\033[1;37m"

.PHONY: all clean fclean re
