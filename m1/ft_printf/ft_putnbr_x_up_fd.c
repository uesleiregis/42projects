
#include "libftprintf.h"

void	ft_putnbr_x_up_fd(unsigned int n, int fd)
{
	char	*hex;
	char	c;

	hex = "0123456789ABCDEF";
	if (n >= 16)
		ft_putnbr_x_up_fd(n / 16, fd);
	c = hex[n % 16];
	write(fd, &c, 1);
}
// int main(void)
// {
//     ft_putnbr_x_up_fd(255, 1); //  ff
//     return (0);
// }
