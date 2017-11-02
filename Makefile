# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/13 16:44:11 by tferrari          #+#    #+#              #
#    Updated: 2017/11/02 15:13:20 by tferrari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: libft

NAME = malloc

SRC_DIR = src

SRC_FILE =	allocate.c found_it.c free.c init_mem.c init_stack.c malloc.c \
			realloc.c show.c check.c new_page.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJS_DIR = obj

OBJS = $(addprefix $(OBJS_DIR)/, $(SRC_FILE:.c=.o))

INC = -ILibft/include -Iinclude

LFT = -L./Libft -lft

all : libft $(NAME)

$(NAME): $(OBJS)
	@gcc $(LFT) -o $(NAME) $(OBJS)
	@echo "\033[32mexecutable lem_in créé\033[0m"

libft:
	make -C Libft/

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@gcc $(INC) -o $@ -c $<
	@echo "Fichier" $< "recompilé."

clean:
	@rm -rf $(OBJS_DIR)
	@make -C Libft clean
	@echo "\033[31mFichier objet de malloc supprimé\033[0m"

fclean: clean
	@rm -f $(NAME)
	@rm -f Libft/libft.a
	@echo "\033[31mLibft.a supprimé\033[0m"
	@echo "\033[31mmalloc supprimé\033[0m"

re: fclean all
