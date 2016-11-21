# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/06 13:15:27 by hhismans          #+#    #+#              #
#    Updated: 2016/11/16 03:50:32 by hhismans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all, clean, fclean, re
NAME = libft.a

CC 	=	gcc
CFLAGS	=	-Wall -Wextra -Werror

SRC		=	\
			ft_putchar.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_putnbrndl.c \
			ft_putendl.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putnbr_fd.c \
			ft_putendl_fd.c \
			\
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			\
			ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			\
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_itoa.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_abs.c \
			ft_taballoc.c \
			ft_strndup.c \
			ft_strnjoin.c \
			ft_strchri.c \
			get_next_line.c \
			ft_dabs.c

SRH		=	libft.h

OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $(OBJ)
	@echo "\033[33mLibrary $@ created."
	@ranlib $@
	@echo "Library $@ indexed.\033[37m"

%.o: %.c $(SRH)
	@$(CC) $(CFLAGS) -o $@ -c $< -I.
	@echo "\033[36mCompilation of \033[1m" $< "\033[0m\033[32m done. \033[37m"
clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: BackToTheFuture fclean all

batman:
	@echo "\033[31m                    ***********************"
	@echo "             *********************************"
	@echo "          *******   *     *       *    *    *******"
	@echo "        *******   ***      **     **     ***   *******"
	@echo "      ******   *****       *********      *****    *****"
	@echo "    ******  ********       *********       ******    *****"
	@echo "   ****   **********       *********       *********   *****"
	@echo "  ****  **************    ***********     ************   ****"
	@echo " ****  *************************************************  ****"
	@echo " ****  ***************************************************  ****"
	@echo " ****  ****************************************************  ****"
	@echo " ****  ****************************************************  ****"
	@echo " ****  ***************************************************  ****"
	@echo "  ****  *******     ****  ***********  ****     *********  ****"
	@echo "   ****   *****      *      *******      *      ********  ****"
	@echo "    *****   ****             *****             ******   *****"
	@echo "      *****   **              ***              **    ******"
	@echo "       ******   *              *              *   *******"
	@echo "         *******                                *******"
	@echo "            ********                         *******"
	@echo "               *********************************"
	@echo "                    *********************** \033[37m"

BackToTheFuture:
	@afplay /Volumes/Data/nfs/sgoinfre/goinfre/Misc/Back\ To\ The\ Future\ \'Twinkle\'\ Ringtone.mp3 >& /dev/null&
	@echo "\033[1;37m              __---~~~~--__                      __--~~~~---__"
	@echo "\033[1;37m             \`\-\033[1;30m--~~~~~~~~\\033[1;37m\\\\                    //~~~~~~~~---/'"
	@echo "\033[1;37m               \/\033[1;30m~~~~~~~~~\|\033[1;37m|                  ||/~~~~~~~~~\/"
	@echo "\033[1;37m                           \`\\\\\                //'"
	@echo "\033[1;37m                             \`\\\\\            //'"
	@echo "\033[1;37m                               ||          ||      Hey Doc!"
	@echo "\033[1;37m                     ______--~~~~~~~~~~~~~~~~~~--______"
	@echo "\033[1;37m                ___ // _-~                        ~-_ \\\\\ ___"
	@echo "\033[0;37m               \`\__)\/~                              ~\/(__/'"
	@echo "\033[0;37m                _--\`-___                            ___-'--_"
	@echo "\033[0;37m              /~     \`\ ~~~~~~~~------------~~~~~~~~ /'     ~\\"
	@echo "\033[0;37m             /|        \`\ \033[1;30m        ________ \033[1;37m        /'        |\\"
	@echo "\033[0;37m            | \`\   ______\`\_ \033[1;30m     \------/  \033[1;37m    _/'______   /' |"
	@echo "\033[0;37m            |   \`\_~-_____\ ~-________________-~ /_____-~_/'   |"
	@echo "\033[0;37m            \`.     ~-__________________________________-~     .'"
	@echo "\033[1;37m             \`.      [_______/------|~~|------\_______]      .'"
	@echo "\033[1;37m              \`\--___((____)(________\/________)(____))___--/'"
	@echo "\033[1;30m                |>>>>>>||                            ||<<<<<<|"
	@echo "\033[1;30m                \`\<<<<</'                            \`\>>>>>/'"


