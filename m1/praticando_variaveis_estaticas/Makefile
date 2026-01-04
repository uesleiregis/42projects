NAME1 = exemplo1_contador
NAME2 = exemplo2_comparacao
NAME3 = exemplo3_gerador_id

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME1) $(NAME2) $(NAME3)

$(NAME1): exemplo1_contador.c
	$(CC) $(CFLAGS) -o $(NAME1) exemplo1_contador.c

$(NAME2): exemplo2_comparacao.c
	$(CC) $(CFLAGS) -o $(NAME2) exemplo2_comparacao.c

$(NAME3): exemplo3_gerador_id.c
	$(CC) $(CFLAGS) -o $(NAME3) exemplo3_gerador_id.c

clean:
	rm -f $(NAME1) $(NAME2) $(NAME3)

re: clean all

.PHONY: all clean re
