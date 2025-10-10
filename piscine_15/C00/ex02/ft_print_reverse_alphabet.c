# include <unistd.h>

void ft_print_reverse_alphabet(void){
	int i = 'z'+1;
	while (i-- >= 'a'+1)
		write(1,&i,1);
}
