# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 22:39:03 by fde-los-          #+#    #+#              #
#    Updated: 2023/08/22 01:06:05 by fde-los-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra

SRC	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c\
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c\
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c\
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c\
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
		ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

OBJ	=	$(SRC:%.c=%.o)

B_SRC	=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

B_OBJ	=	$(B_SRC:%.c=%.o)

RM	=	rm -f

AR	=	ar -cr

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus: $(OBJ) $(B_OBJ)
	$(AR) $(NAME) $(OBJ) $(B_OBJ)

clean:
	$(RM) $(OBJ) $(B_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.SILENT: all $(NAME) $(OBJ) clean fclean
.PHONY: all clean fclean re
