#include "libftprintf.h"

int ft_print_x(unsigned int n, int fd)
{
	unsigned long	x;
	int		count;

    count = 0;
    x = (unsigned long)n;
	if(x == 0)
		count++;
  while(x > 0)
  {
		x/=16;
		count++;
  }
	ft_putnbr_x_fd(n, fd);
    return (count);
}