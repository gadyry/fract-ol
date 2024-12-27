# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/27 13:38:20 by ael-gady          #+#    #+#              #
#    Updated: 2024/12/27 13:40:20 by ael-gady         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c events.c handle_std_utils.c julia_set.c mandelbrot.c math_utils.c warmest_color.c
		   
OBJ_SRC = $(SRC:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror
FRM = -lmlx -framework OpenGL -framework AppKit

%.o : %.c fractol.h
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ_SRC)
	$(CC) $(FLAGS) $(OBJ_SRC) $(FRM) -o $(NAME)

clean :
	rm -f $(OBJ_SRC)

fclean : clean
	rm -f $(NAME)
re : fclean all
