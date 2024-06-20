# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 21:58:13 by npentini          #+#    #+#              #
#    Updated: 2024/06/19 04:20:13 by npentini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = mandatory/ft_printf.c mandatory/ft_printf_process1.c mandatory/ft_printf_process2.c mandatory/ft_printf_utils.c
B_SRCS = bonus/ft_printf_bonus.c bonus/ft_printf_process1_bonus.c bonus/ft_printf_process2_bonus.c bonus/ft_printf_utils_bonus.c bonus/ft_printf_flag_utils_bonus.c bonus/ft_printf_print_process1_bonus.c bonus/ft_printf_print_process1_ext_bonus.c bonus/ft_printf_print_process2_bonus.c
INCS = includes/
COMP = cc -c
CFLAGS = -Wall -Wextra -Werror
DELETE = rm -f
LIB_CREATE = ar rcs
RANLIB = ranlib
OBJS = $(SRCS:%.c=%.o)
B_OBJS = $(B_SRCS:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(COMP) $(CFLAGS) -I $(INCS) -o $@ $< -g

$(NAME): $(OBJS)
	$(LIB_CREATE) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

bonus: $(B_OBJS)
	$(LIB_CREATE) $(NAME) $(B_OBJS)
	$(RANLIB) $(NAME)

clean:
	$(DELETE) $(OBJS) $(B_OBJS)

fclean: clean
	$(DELETE) $(NAME)

re: fclean all

.PHONY: all clean fclean re