# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/19 18:46:08 by mmoullec          #+#    #+#              #
#    Updated: 2016/12/01 16:58:38 by mmoullec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc -Wall -Werror -Wextra
SRC = ft_atoi.c\
	ft_bzero.c\
	ft_char_cmp.c\
ft_count_words.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_isspace.c\
ft_itoa.c\
ft_lstadd.c\
ft_lstdel.c\
ft_lstdelone.c\
ft_lstiter.c\
ft_lstmap.c\
ft_lstnew.c\
ft_memalloc.c\
ft_memccpy.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memdel.c\
ft_memmove.c\
ft_memset.c\
ft_putchar.c\
ft_putchar_fd.c\
ft_putendl.c\
ft_putendl_fd.c\
ft_putnbr.c\
ft_putnbr_fd.c\
ft_putnbr_endl.c\
ft_putstr.c\
ft_putstr_fd.c\
ft_strcat.c\
ft_strchr.c\
ft_strclr.c\
ft_strcmp.c\
ft_strcpy.c\
ft_strdel.c\
ft_strdup.c\
ft_strequ.c\
ft_striter.c\
ft_striteri.c\
ft_strjoin.c\
ft_strlcat.c\
ft_strlen.c\
ft_strmap.c\
ft_strmapi.c\
ft_strncat.c\
ft_strncmp.c\
ft_strncpy.c\
ft_strnequ.c\
ft_strnew.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strrev.c\
ft_strsplit.c\
ft_strstr.c\
ft_strsub.c\
ft_strtrim.c\
ft_tolower.c\
ft_toupper.c\
ft_putstr_sp.c\
ft_putendl_sp.c\
get_next_line.c\
ft_atoi_base.c\
ft_convert_base.c\
ft_len_nb.c\
ft_lstadd_s.c\
ft_freeone.c\
ft_atof.c\
ft_tab_clr.c\
ft_lstadd_n.c\
ft_lstnew_n.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "compil lib"
	@ar rc $(NAME) $? $(OBJ)
	@echo "ok"
	@echo "ranlib"
	@ranlib $(NAME)
	@echo "ok"


%.o: %.c
	@$(CC) -o $@ -c $< -I.
	@echo $@ " ok"

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
