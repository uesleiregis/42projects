#include "libftprintf.h"

int ft_print_p(void *ptr, int fd)
{
	unsigned long	addr;
	unsigned long	x;
	int				count;

	if (!ptr)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	addr = (unsigned long)ptr;
	x = addr;
	ft_putstr_fd("0x", fd);
	count = 2;
	if(x == 0)
		count++;
	while (x > 0)
	{
		x /= 16;
		count++;
	}
	ft_putnbr_x_fd(addr, fd);
	return (count);
}