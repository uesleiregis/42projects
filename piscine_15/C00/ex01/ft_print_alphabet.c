#include <unistd.h>

void	ft_print_alphabet(void)
{
	int i = 'a' - 1;
	while(i++ <= 'z' - 1)
		write(1,&i,1);
}
