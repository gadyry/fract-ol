# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/29 17:40:57 by ael-gady          #+#    #+#              #
#    Updated: 2024/12/31 09:49:08 by ael-gady         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror -O3

NAME = fractol

BNAME = fractol_bonus

MPATH = ./mandatory/

BPATH = ./bonus/

CFILES =  $(MPATH)main.c 	$(MPATH)events.c 	$(MPATH)handle_std_utils.c 	$(MPATH)julia_set.c \
 			$(MPATH)mandelbrot.c 	$(MPATH)math_utils.c $(MPATH)warmest_color.c

BFILES = $(BPATH)main_bonus.c $(BPATH)event_bonus.c $(BPATH)handle_std_bonus_utils.c $(BPATH)julia_set_bonus.c \
		$(BPATH)mandelbrot_bonus.c $(BPATH)math_bonus_utils.c $(BPATH)warmest_color_bonus.c  $(BPATH)tricorn_bonus.c \
		$(BPATH)canopy.c
OFILES = $(CFILES:.c=.o)

BOFILES = $(BFILES:.c=.o)

all : $(NAME)
	@echo "\x1b[32m============================="
	@echo "=        All Done ✅        ="
	@echo "=============================\x1b[0m"

$(NAME) : $(OFILES) $(MPATH)fractol.h
	@$(CC) $(FLAGS) -lmlx -framework OpenGL -framework AppKit $(OFILES) -o $@

$(MPATH)%.o : $(MPATH)%.c $(MPATH)fractol.h
	@echo "\x1b[36mCompiling $< .\x1b[0m"
	@sleep 0.2
	@echo "\x1b[36mCompiling $< ..\x1b[0m"
	@sleep 0.2
	@echo "\x1b[36mCompiling $< ...\x1b[0m"
	@sleep 0.2
	@echo "\x1b[36mCompiling $< .\x1b[0m"
	@sleep 0.2
	@echo "\x1b[36mCompiling $< ..\x1b[0m"
	@sleep 0.2
	@$(CC) $(FLAGS) -Imlx -c $< -o $@
	@echo "\x1b[32mCompilation successful! 🚀\x1b[0m"
	
bonus : $(BNAME)
	@echo "\x1b[32m============================="
	@echo "=        All Done ✅        ="
	@echo "=============================\x1b[0m"

$(BNAME) : $(BOFILES) $(BPATH)fractol_bonus.h
	@$(CC) $(FLAGS) -lmlx -framework OpenGL -framework AppKit $(BOFILES) -o $@

$(BPATH)%.o : $(BPATH)%.c $(BPATH)fractol_bonus.h
	@echo "\x1b[36mCompiling $< .\x1b[0m"
	@sleep 0.2
	@echo "\x1b[36mCompiling $< ..\x1b[0m"
	@sleep 0.2
	@echo "\x1b[36mCompiling $< ...\x1b[0m"
	@sleep 0.2
	@echo "\x1b[36mCompiling $< .\x1b[0m"
	@sleep 0.2
	@echo "\x1b[36mCompiling $< ..\x1b[0m"
	@sleep 0.2
	@$(CC) $(FLAGS) -Imlx -c $< -o $@
	@echo "\x1b[32mCompilation successful! 🚀\x1b[0m"

clean :
	@echo "\x1b[33mCleaning up.\x1b[0m"
	@sleep 0.2
	@echo "\x1b[33mCleaning up..\x1b[0m"
	@sleep 0.2
	@echo "\x1b[33mCleaning up...\x1b[0m"
	@sleep 0.2
	@echo "\x1b[33mCleaning up.\x1b[0m"
	@sleep 0.2
	@echo "\x1b[33mCleaning up..\x1b[0m"
	@sleep 0.2
	@rm -f $(OFILES) $(BOFILES)
	@echo "\x1b[32mCleanup complete! 🧹\x1b[0m"

fclean : clean
	@rm -f $(NAME) $(BNAME)

re : fclean all