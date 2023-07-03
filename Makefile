# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 12:57:07 by rimarque          #+#    #+#              #
#    Updated: 2023/07/03 22:55:26 by rimarque         ###   ########.fr        #
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
SRC_PARSE_MAP = ./parse_map
SRC_AUX = ./aux
SRC_DRAW_MAP = ./draw_map
LIBFT_PATH = ./libftx
MLX_PATH = ./mlx

#-----------------------------------  FILES  --------------------------------
NAME = fdf

LIBFT = ./libftx/libft.a

MLX = ./mlx/libmlx.a

SRC = $(SRC_PARSE_MAP)/parse_map.c \
		$(SRC_PARSE_MAP)/create_map.c \
		$(SRC_AUX)/aux_map.c \
		$(SRC_AUX)/set_vars.c \
		$(SRC_AUX)/aux_x_max.c \
		$(SRC_AUX)/scale.c \
		$(SRC_AUX)/math.c \
		$(SRC_AUX)/map_lim.c \
		$(SRC_DRAW_MAP)/draw_map.c \

#----------------------------------  RULES  ----------------------------------
all: $(NAME) $(LIBFT) $(MLX)

$(LIBFT):
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)LIBFT$(RESET)"
	make $(NPD) -C $(LIBFT_PATH)

$(MLX):
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)MLX$(RESET)"
	make $(NPD) -C $(MLX_PATH)

$(NAME): $(SRC) $(LIBFT) $(MLX)
	echo "[$(CYAN) Linking $(RESET)] $(GREEN)$(RESET)"
	$(CC) $(CFLAGS) fdf.c $(SRC) $(MLX) $(CMLX) $(LIBFT) -o $(NAME)
	echo "$(GREEN)Program READY!$(RESET)"

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

run: all clean
		echo ""
		 ./fdf maps/10-2.fdf
		 ./fdf maps/10-70.fdf
		 ./fdf maps/20-60.fdf
		 ./fdf maps/42.fdf
		 ./fdf maps/50-4.fdf
		 ./fdf maps/100-6.fdf
		 ./fdf maps/basictest.fdf
		 ./fdf maps/elem-col.fdf
		 ./fdf maps/elem-fract.fdf
		 ./fdf maps/elem.fdf
		 ./fdf maps/plat.fdf
		 ./fdf maps/pnp_flat.fdf
		 ./fdf maps/julia.fdf
		 ./fdf maps/mars.fdf
		 ./fdf maps/pylone.fdf
		 ./fdf maps/pyra.fdf
		 ./fdf maps/pyramide.fdf
		 ./fdf maps/t1.fdf
		 ./fdf maps/t2.fdf

.SILENT:

.PHONY: all clean fclean re
