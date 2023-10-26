# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-los- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 19:09:09 by fde-los-          #+#    #+#              #
#    Updated: 2023/10/26 10:33:01 by fde-los-         ###   ########.fr        #
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

SRCS_B	=	server_bonus.c

OBJS_B	=	$(SRCS_B:%.c=%.o)

SRCC_B	=	client_bonus.c

OBJC_B	=	$(SRCC_B:%.c=%.o)

RM	=	rm -f

all:		$(NAMES) $(NAMEC)

$(NAMES):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAMES)

$(NAMEC): 	$(OBJC)
			$(CC) $(CFLAGS) $(OBJC) -o $(NAMEC)

bonus:		$(OBJS_B) $(OBJC_B)
			$(CC) $(CFLAGS) $(OBJS_B) -o $(NAMES)
			$(CC) $(CFLAGS) $(OBJC_B) -o $(NAMEC)

clean:
			$(RM) $(OBJS) $(OBJC) $(OBJS_B) $(OBJC_B)

fclean: 	clean
			$(RM) $(NAMES) $(NAMEC)

re: 		fclean all

.SILENT: all $(NAMES) $(OBJS) $(NAMEC) $(OBJC) bonus clean fclean
.SILENT: $(OBJS_B) $(OBJC_B)
.PHONY: all clean fclean re bonus
