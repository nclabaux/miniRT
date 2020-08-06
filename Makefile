# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/05 18:28:50 by nclabaux          #+#    #+#              #
#    Updated: 2020/08/06 14:52:18 by nclabaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

SRCS =	srcs/bmp.c\
	srcs/calculus.c\
	srcs/clear.c\
	srcs/colors.c\
	srcs/distances.c\
	srcs/errors.c\
	srcs/file_reading0.c\
	srcs/file_reading1.c\
	srcs/file_reading2.c\
	srcs/file_reading3.c\
	srcs/images.c\
	srcs/light.c\
	srcs/intersection.c\
	srcs/intersection_cy.c\
	srcs/list_handling.c\
	srcs/loop.c\
	srcs/main.c\
	srcs/ray.c\
	srcs/set_data.c\
	srcs/utils.c\
	srcs/vectorial_calculus0.c\
	srcs/vectorial_calculus1.c\
	srcs/verification0.c\
	srcs/verification1.c

SRCS_BONUS =	bonus/bmp_bonus.c\
	bonus/calculus_bonus.c\
	bonus/clear_bonus.c\
	bonus/colors_bonus.c\
	bonus/distances_bonus.c\
	bonus/errors_bonus.c\
	bonus/file_reading0_bonus.c\
	bonus/file_reading1_bonus.c\
	bonus/file_reading2_bonus.c\
	bonus/file_reading3_bonus.c\
	bonus/filter_bonus.c\
	bonus/images_bonus.c\
	bonus/light_bonus.c\
	bonus/intersection_bonus.c\
	bonus/intersection_cy_bonus.c\
	bonus/list_handling_bonus.c\
	bonus/loop_bonus.c\
	bonus/main_bonus.c\
	bonus/ray_bonus.c\
	bonus/set_data_bonus.c\
	bonus/utils_bonus.c\
	bonus/vectorial_calculus0_bonus.c\
	bonus/vectorial_calculus1_bonus.c\
	bonus/verification0_bonus.c\
	bonus/verification1_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

SAVE_DIR = saves/

CC = clang 

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

LIBFLAGS = -L./minilibx-linux -lm -lmlx -lXext -lX11 -L./libft -lft

$(NAME): $(OBJS)
	make -C minilibx-linux/
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFLAGS)
	mkdir -p $(SAVE_DIR)

all: $(NAME)

clean: 
	make -C minilibx-linux/ clean
	make -C libft/ clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	make -C libft/ fclean
	$(RM) $(NAME) $(SAVE_DIR)

re: fclean all

bonus: $(OBJS_BONUS)
	make -C minilibx-linux/
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS_BONUS) $(LIBFLAGS)
	mkdir -p $(SAVE_DIR)

.PHONY: all clean fclean re bonus
