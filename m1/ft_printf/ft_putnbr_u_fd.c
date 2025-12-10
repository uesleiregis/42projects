
#include "libftprintf.h"

void	ft_putnbr_u_fd(unsigned int n, int fd)
{
	char	c;

	if (n >= 10)
		ft_putnbr_u_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}
// int main(void)
// {
//     ft_putnbr_u_fd(137, 1);
//     return (0);
// }
