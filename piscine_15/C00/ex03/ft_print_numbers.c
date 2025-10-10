#include <unistd.h>
void ft_print_numbers(void)
{
	int c = '0' - 1;
	while(c++ <= '9' - 1)
		write(1,&c,1);
}
