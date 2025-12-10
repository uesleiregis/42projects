
#include "libftprintf.h"
// TODO Ver a lógica completa, olhar sugestões da IA também.
void	ft_putnbr_x_fd(unsigned int n, int fd)
{
	char	*hex;
	char	c;

	hex = "0123456789abcdef";
	if (n >= 16)
		ft_putnbr_x_fd(n / 16, fd);
	c = hex[n % 16];
	write(fd, &c, 1);
}
// int main(void)
// {
//     ft_putnbr_x_fd(255, 1); // ff
//     return (0);
// }
