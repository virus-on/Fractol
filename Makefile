# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 15:22:42 by vpopovyc          #+#    #+#              #
#    Updated: 2016/11/27 12:12:26 by mpaziuk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c \
      ft_tools.c \
      mandelvrot.c \
      julia.c \
      ship.c \
      ft_hooks.c \

OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -O3 -pthread
GFLAGS = -lmlx -framework OpenGL -framework AppKit 

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	gcc $(OBJ) libft/libft.a -I libft -o $(NAME) $(GFLAGS)

%.o: %.c fractol.h
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

libft/libft.a:
	make -C libft