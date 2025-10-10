
#include <unistd.h>

void ft_putstr(char *str){
    while (*str != '\0'){
        write(1,str,1);
        str++;
    }
    write(1,"\n",1); // nao precisa por tamanho 2 porque o \0 nao precisa ser impresso e o write já impede o loop
// write espera um ponteiro no segundo argumento, isso é importante.!!!
}


int main(){
    char nome[] = "Maria";
    char *p=nome;

    ft_putstr(p);

    return 0;
}
