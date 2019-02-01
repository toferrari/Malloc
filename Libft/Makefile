# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/12 18:19:54 by tferrari          #+#    #+#              #
#    Updated: 2019/01/30 19:34:55 by tferrari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

FLAG = -Wall -Werror -Wextra

SRC_DIR = src

SRC_FILE =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
			ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
			ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
			ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_tolower.c ft_toupper.c ft_memalloc.c ft_memdel.c \
			ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
			ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
			ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
			ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
			ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
			ft_intlen.c ft_reverse_nb.c ft_nbword.c ft_nbletter.c ft_fill.c \
			ft_putstrnbr.c ft_putnbrendl.c ft_realloc_chr.c ft_realloc_adr.c \
			ft_strclen.c ft_strccat.c ft_strnchr.c ft_strputnchr.c \
			ft_strnccat.c ft_intlen_64.c ft_itoa_64.c ft_strlnccat.c \
			ft_strcat_p.c ft_realloc_adr_p.c ft_intlen_base.c ft_itoa_base.c \
			ft_intlen_base64.c ft_itoa_base64.c ft_strupper.c ft_wchar_len.c \
			ft_wchrcat.c ft_strccat_p.c ft_strcpy_p.c ft_wstr_len.c \
			ft_intmal.c get_next_line.c ft_swap.c \
			ft_call_arg.c ft_convert_signe.c ft_wchar_to_char.c ft_flag.c \
			ft_flag_d.c ft_flag_hhu.c ft_flag_hho.c ft_flag_hhx.c ft_flag_hd.c \
			ft_flag_ho.c ft_flag_hexa.c ft_flag_lld.c ft_flag_llu.c \
			ft_flag_octal.c ft_flag_pourcent.c ft_flag_str.c ft_flag_u.c \
			ft_parse_flag.c ft_flag_llhexa.c ft_flag_c_null.c ft_flag_chr.c \
			ft_flag_wchr.c ft_flag_wstr.c ft_flag_hhd.c ft_flag_llo.c \
			ft_flag_p.c ft_printf.c ft_flag_b.c ft_putnbr_base.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJS_DIR = obj

OBJS = $(addprefix $(OBJS_DIR)/, $(SRC_FILE:.c=.o))

INC = -I ./include/

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "compiler"

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@gcc $(FLAG) $(INC) -c $< -o $@
	@echo "Fichier" $< "recompilé."

clean:
	@rm -rf $(OBJS_DIR)
	@echo "Fichier obj libft efface"

fclean: clean
	@rm -f $(NAME)
	@echo "Libft efface"

re: fclean all
