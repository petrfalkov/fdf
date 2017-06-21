# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichubare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/25 14:43:13 by ichubare          #+#    #+#              #
#    Updated: 2017/02/26 14:31:32 by ichubare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf.c \
	  calc_angle.c \
	  draw_map.c \
	  key_act.c \
	  mapa.c \

OBJ = $(SRC:.c=.o)

HEADER = fdf.h

OFLAGS = -Wall -Wextra -Werror -O2 -c

GFLAGS = -lmlx -framework OpenGl -framework AppKit

all: $(NAME)
	
$(NAME): $(OBJ)
		gcc $(OFLAGS) $(SRC)
		gcc -o $(NAME) ft_printf/libftprintf.a $(OBJ) $(GFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
