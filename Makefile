# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 20:10:13 by mcauchy           #+#    #+#              #
#    Updated: 2025/04/27 12:13:32 by macauchy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	=	ft_printf.c utils.c utils2.c

SRC_DIR	=	srcs

SRCS	=	$(addprefix $(SRC_DIR)/, $(FILES))

OBJ_DIR	=	.objs

OBJS	=	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

NAME	=	libftprintf.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	/bin/rm -rf

HEADER	=	includes/ft_printf.h

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADER)
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
