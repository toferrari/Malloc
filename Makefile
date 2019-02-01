# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/13 16:44:11 by tferrari          #+#    #+#              #
#    Updated: 2019/01/30 16:56:50 by tferrari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: libft

ifeq ($(HOSTTYPE),)
	HOSTTYPE = $(shell uname -m)_$(shell uname -s)
endif

NAME =	libft_malloc_$(HOSTTYPE).so

MALLOCLIB =	libft_malloc.so

SOFLAGS	=	-shared

FLAGS = -Wall -Werror -Wextra

SRC_DIR = src

SRC_FILE =	allocate.c found_it.c free.c init_mem.c init_stack.c malloc.c \
			realloc.c show.c check.c new_page.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJS_DIR = obj

OBJS = $(addprefix $(OBJS_DIR)/, $(SRC_FILE:.c=.o))

INC = -ILibft/include -Iinclude

LFT = -L./Libft -lft

all : libft $(NAME) link_malloc

$(NAME): $(OBJS)
	@gcc $(SOFLAGS) $(LFT) -o $(NAME) $(OBJS) $(FLAGS)
	@echo "\033[32mexecutable malloc créé\033[0m"

libft:
	make -C Libft/

link_malloc:
	rm -f $(MALLOCLIB)
	ln -s $(NAME) $(MALLOCLIB)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@gcc $(FLAGS) $(INC) -o $@ -c $< $(FLAGS)
	@echo "Fichier" $< "recompilé."

clean:
	@rm -rf $(OBJS_DIR)
	@make -C Libft clean
	@echo "\033[31mFichier objet de malloc supprimé\033[0m"

fclean: clean
	@rm -f $(NAME)
	@rm -f libft_malloc.so
	@rm -f Libft/libft.a
	@echo "\033[31mLibft.a supprimé\033[0m"
	@echo "\033[31mmalloc supprimé\033[0m"

re: fclean all
