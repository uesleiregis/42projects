# include "libftprintf.h"

int    ft_print_s(char *s, int fd)
{
   
    if (!s)
        s = "(null)";
    ft_putstr_fd(s, fd);
    return (ft_strlen(s));
}