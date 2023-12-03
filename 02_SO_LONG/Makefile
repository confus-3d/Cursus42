# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 22:39:03 by fde-los-          #+#    #+#              #
#    Updated: 2023/08/22 11:24:47 by fde-los-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	solong

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

MLXFLAGS=	-Lmlx -lmlx -framework OpenGL -framework AppKit

SRC		=	prueba.c

OBJ		=	$(SRC:%.c=%.o)

RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(MLXFLAGS) $(OBJ) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.SILENT: all $(NAME) $(OBJ) bonus clean fclean
.PHONY: all clean fclean re bonus
