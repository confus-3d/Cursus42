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

NAME	=	libftprintf.a

LIBFT	=	./libft/libft.a

LIBFTDIR=	./libft

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:%.c=%.o)

RM	=	rm -f

AR	=	ar -cr

CP	=	cp

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
			$(CP) $(LIBFT) $(NAME)
			$(AR) $(NAME) $(OBJ)

$(LIBFT): 	$(LIBFTDIR)
			$(MAKE) -C $(LIBFTDIR)

clean:
			$(MAKE) clean -C $(LIBFTDIR)
			$(RM) $(OBJ)

fclean: 	clean
			$(MAKE) fclean -C $(LIBFTDIR)
			$(RM) $(NAME)

re: 		fclean all

.SILENT: all $(NAME) $(OBJ) $(LIBFT) bonus clean fclean
.PHONY: all clean fclean re bonus
