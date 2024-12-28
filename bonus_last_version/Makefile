# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 15:44:35 by ael-gady          #+#    #+#              #
#    Updated: 2024/12/28 15:59:46 by ael-gady         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol_bonus

SRC = main_bonus.c event_bonus.c handle_std_bonus_utils.c julia_set_bonus.c \
	mandelbrot_bonus.c math_bonus_utils.c warmest_color_bonus.c
		   
OBJ_SRC = $(SRC:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror
FRM = -lmlx -framework OpenGL -framework AppKit

%.o : %.c fractol_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ_SRC)
	$(CC) $(FLAGS) $(OBJ_SRC) $(FRM) -o $(NAME)

clean :
	rm -f $(OBJ_SRC)

fclean : clean
	rm -f $(NAME)
re : fclean all