# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/10 10:33:06 by knovytsk          #+#    #+#              #
#    Updated: 2018/01/10 12:48:55 by knovytsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = srcs/main.c srcs/image.c srcs/fractal_init.c srcs/mouse_events.c\
	   srcs/key_events.c srcs/color.c srcs/fractal_set1.c srcs/hook.c\
	   srcs/fractal_set2.c srcs/errors.c srcs/data.c srcs/params.c
LIBFT = -C libft
CC = gcc -Wall -Wextra -Werror
INCLUDES = -I includes 
FLAGS = -lmlx -framework OpenGL -framework AppKit -Ofast
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: $(SRCS_PATH)/%.c
	@$(CC) -c $< $(INCLUDES) -o $@

$(NAME): $(OBJS)
	@echo "\033[35mCompilation of libft...\033[0m"
	@make $(LIBFT)
	@$(CC) -o $(NAME) $(OBJS) libft/libft.a $(FLAGS)
	@echo "\033[36mFRACTOL IS COMPILED\033[0m"

clean: 
	@make clean -C libft
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f libft/libft.a
	@/bin/rm -f $(NAME)
	@echo "\033[33mCleaned\033[0m"

re: fclean all

.PHONY: clean fclean re all
