# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/29 16:27:03 by azinnatu          #+#    #+#              #
#    Updated: 2018/05/10 18:04:07 by azinnatu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = -Wall -Wextra -Werror -g
CC = gcc

SRC =	main.c \
		ft_env.c \
		ft_setenv.c \
		ft_unsetenv.c \
		ft_dir.c \
		cd_env_change.c \
		ft_echo.c \
		ft_cmd.c 

LIBFT = libft/libft.a
FT_PRINTF = libft/ft_printf/libftprintf.a

LIB		= -L libft/ -l ft -L libft/ft_printf/ -l ftprintf
INC		= -I includes/

OB1 = $(SRC:.c=.o)
OBJ = $(SRCS:.c=.o)

OBJS = $(addprefix $(OBJDIR)/, $(OBJ))

HEADER = minishell.h

RM = rm -rf

GREEN = \033[32m
RED = \033[31m

all : $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@make -C libft/ft_printf
	$(CC) $(FLAGS) $(INC) -c $(SRC)
	$(CC) $(FLAGS) $(LIB) $(OB1) -o $(NAME)
	@echo "Building a minishell..."

rmbin:
	rm -rf $(NAME)

rmobj:
	rm -rf *.o

again: rmbin rmobj all
	

clean:
	@/bin/$(RM) $(OB1)
	@make -C libft clean
	@make -C libft/ft_printf clean
	@echo "Cleaning up *.o files..."

fclean: clean
	@make -C $(dir $(LIBFT)) fclean
	@make -C libft/ft_printf fclean
	@/bin/$(RM) $(NAME)
	@echo "$(RED)minishell: deleting object files"

re: fclean all

.PHONY: all clean fclean re
