NAME	=	libft.a

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:%.c=%.o)

RM	=	rm -f

AR	=	ar -cr

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.SILENT: all $(NAME) $(OBJ) clean fclean
.PHONY: all clean fclean re
