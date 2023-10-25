# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-los- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 19:09:09 by fde-los-          #+#    #+#              #
#    Updated: 2023/10/25 19:28:39 by fde-los-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMES	=	server

NAMEC	=	client

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

SRCS	=	server.c

OBJS	=	$(SRCS:%.c=%.o)

SRCC	=	client.c

OBJC	=	$(SRCC:%.c=%.o)

RM		=	rm -f

all:		$(NAMES) $(NAMEC)

$(NAMES):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAMES)

$(NAMEC): 	$(OBJC)
			$(CC) $(CFLAGS) $(OBJC) -o $(NAMEC)

clean:
			$(RM) $(OBJS) $(OBJC)

fclean: 	clean
			$(RM) $(NAMES) $(NAMEC)

re: 		fclean all

.SILENT: all $(NAMES) $(OBJS) $(NAMEC) $(OBJC) bonus clean fclean
.PHONY: all clean fclean re bonus
