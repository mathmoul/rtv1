NAME = libmy_math.a
CC = clang -Wall -Werror -Wextra
SRC = cubic_eq.c\
quartic_solver.c\
my_math1.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $? $(OBJ)
	@ranlib $(NAME)
	@echo "Created" $(NAME)

%.o: %.c
	@$(CC) $(LMLX) -o $@ -c $< -I.
	@echo $@ "Created"

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
