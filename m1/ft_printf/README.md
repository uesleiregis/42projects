
Para testar o projeto.

make re // para gerar a biblioteca
cc -Wall -Werror -Wextra teste.c libftprintf.a -o teste // gerando o executável
./teste. // executando o comando.

O projeto atual visa principalmente fortalecer o entendimento das funções variáticas e um entendimento mais profundo da função printf da linguagem C.
Recriei a função printf.c com o nome ft_printf a qual deve aceitar as conversões %c, %s, %p, %d, %i, %u, %x, %X, %%. Algumas funções da biblioteca libft foram utilizadas no projeto, bem como outras funões próprias para o projeto atual e suas respectivas modificações. Tais funções foram compiladsa na biblioteca libftprintf.a