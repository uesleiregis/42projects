#include <stdio.h>

char *ft_strcat(char *dest, char *src){
    char *p= dest;
  
    while(*dest){
        dest++;
    }
    
    while(*src){
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';

    return (p);
}

int main(){
    char nome1[20] = "";
    char nome2[20] = "Hello";
    char nome3[5] = "Ana";

    char *a= ft_strcat(nome1, nome2); // Hello
    char *b= ft_strcat(nome2, nome3); // HelloAna
    //char c[]= ft_strcat(nome3, nome2); // AnaHe

    printf("%s\n", a); // apelido para dest , que é nome1 
    printf("%s\n", b); // apelido para dest, que é nome2
    //printf("%s\n", c);

    return 0;
}
