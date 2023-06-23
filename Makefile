# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 12:57:07 by rimarque          #+#    #+#              #
#    Updated: 2023/06/23 18:52:36 by rimarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-------------------------------------  COLORS  --------------------------------
RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
PURPLE 	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

#------------------------------------  COMMANDS  ------------------------------
CC = cc
RM = rm -rf

#------------------------------------  FLAGS  ---------------------------------
CFLAGS	= -Wall -Wextra -Werror -g #-fsanitize=address
NPD		= --no-print-directory
CMLX	= -Ilmlx -lXext -lX11 -lm

#-----------------------------------  FOLDERS  --------------------------------
SRC_PATH = .
SRC_MAND_PATH =
SRC_BONUS_PATH =
LIBFT_PATH = ./libftx
MLX_PATH = ./mlx

#-----------------------------------  FILES  --------------------------------
NAME = fdf

LIBFT = ./libftx/libft.a

MLX = ./mlx/libmlx.a

SRC = $(SRC_PATH)/fdf.c \
		$(SRC_PATH)/read_map.c \
		$(SRC_PATH)/list.c \
		$(SRC_PATH)/math.c \


#OBJ_MAND = $(SRC_MAND)/

#NAME_BONUS = fdf_bonus

#OBJ_BONUS = $(SRC_BONUS)/

#----------------------------------  RULES  ----------------------------------
all: $(NAME) $(LIBFT) $(MLX)

$(LIBFT):
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)LIBFT$(RESET)"
	make $(NPD) -C $(LIBFT_PATH)

$(MLX):
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)MLX$(RESET)"
	make $(NPD) -C $(MLX_PATH)

$(NAME): $(OBJ_MAND) $(LIBFT) $(MLX)
	echo "[$(CYAN) Linking $(RESET)] $(GREEN)$(RESET)"
	$(CC) $(CFLAGS) $(SRC) $(MLX) $(CMLX) $(LIBFT) -o $(NAME)
	echo "$(GREEN)Program READY!$(RESET)"

#bonus: $(NAME_BONUS)

#$(NAME_BONUS): $(OBJ_BONUS) $(OBJ) $(LIBFT)
#		$(CC) $(CFLAGS) $(OBJ_BONUS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME_BONUS)
#		echo "$(GREEN)Bonus READY!$(RESET)"

clean:
	make clean $(NPD) -C $(LIBFT_PATH)
	make clean $(NPD) -C $(MLX_PATH)
	rm -rf $(OBJ)
	rm -rf $(OBJ_MAND)
	rm -rf $(OBJ_BONUS)
	echo "Object files CLEAN"

fclean: clean
	$(MAKE) fclean $(NPD) -C ./libftx
	rm -rf $(NAME)
	rm -rf bonus
	echo "All files CLEAN"

re: fclean all

bre: fclean bonus

.SILENT:

.PHONY: all clean fclean re
