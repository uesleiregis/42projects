NAME = ft_display_file
CCFLAGS = cc -Wall -Wextra -Werror
SRC = display_file.c
OBJ = display_file.o

all: $(NAME)

$(NAME): $(OBJS)
	$(CCFLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	$(CCFLAGS) $(SRC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean

