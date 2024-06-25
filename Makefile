# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 17:30:35 by npentini          #+#    #+#              #
#    Updated: 2024/06/25 02:49:24 by npentini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
CLIENT_NAME = client
SERVER_BONUS_NAME = server_bonus
CLIENT_BONUS_NAME = client_bonus
SERVER_SRCS = mandatory/server.c
CLIENT_SRCS = mandatory/client.c
SERVER_SRCS_BONUS = bonus/server_bonus.c
CLIENT_SRCS_BONUS = bonus/client_bonus.c
INCS = includes/.
FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a
COMP = cc
CFLAGS = -Wall -Wextra -Werror
DELETE = rm -f
 
all: $(FT_PRINTF_LIB) $(SERVER_NAME) $(CLIENT_NAME)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(SERVER_NAME):
	$(COMP) $(CFLAGS) $(SERVER_SRCS) $(FT_PRINTF_LIB) -o $(SERVER_NAME)

$(CLIENT_NAME):
	$(COMP) $(CFLAGS) $(CLIENT_SRCS) $(FT_PRINTF_LIB) -o $(CLIENT_NAME)

bonus: $(FT_PRINTF_LIB) $(SERVER_BONUS_NAME) $(CLIENT_BONUS_NAME)

$(SERVER_BONUS_NAME):
	$(COMP) $(CFLAGS) $(SERVER_SRCS_BONUS) $(FT_PRINTF_LIB) -o $(SERVER_BONUS_NAME)

$(CLIENT_BONUS_NAME):
	$(COMP) $(CFLAGS) $(CLIENT_SRCS_BONUS) $(FT_PRINTF_LIB) -o $(CLIENT_BONUS_NAME)
	
clean:
	$(DELETE) $(SERVER_OBJS) $(CLIENT_OBJS)
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	$(DELETE) $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_BONUS_NAME) $(CLIENT_BONUS_NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re