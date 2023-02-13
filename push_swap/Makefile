# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 20:36:30 by cegbulef          #+#    #+#              #
#    Updated: 2023/01/08 08:48:08 by cegbulef         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
CC		=	gcc -g
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm	-rf

SRCS 	=	push_swap.c utils.c operations.c sort.c operations2.c operations3.c \
			commands.c utils2.c utils3.c operations4.c radix_sort.c utils4.c sort2.c error.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY = all clean fclean re