#include "libftprintf.h"

static void	ft_putnbr_ptr(unsigned long n, int fd)
{
	char	*hex;
	char	c;

	hex = "0123456789abcdef";
	if (n >= 16)
		ft_putnbr_ptr(n / 16, fd);
	c = hex[n % 16];
	write(fd, &c, 1);
}

int	ft_print_p(void *ptr, int fd)
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
	if (x == 0)
		count++;
	while (x > 0)
	{
		x /= 16;
		count++;
	}
	ft_putnbr_ptr(addr, fd);
	return (count);
}