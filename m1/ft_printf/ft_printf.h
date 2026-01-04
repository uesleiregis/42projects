/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ueslei <ueslei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:12:28 by uregis-d          #+#    #+#             */
/*   Updated: 2026/01/04 12:12:10 by ueslei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FD 1

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/* Useful ft_printf functions */
int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);

/* Print functions by descriptor */
int		ft_print_c(char c, int fd);
int		ft_print_s(char *s, int fd);
int		ft_print_p(void *ptr, int fd);
int		ft_print_d(int n, int fd);
int		ft_print_i(int n, int fd);
int		ft_print_u(unsigned int n, int fd);
int		ft_print_x(unsigned int n, int fd);
int		ft_print_x_up(unsigned int n, int fd);

/* Auxiliary numeric print functions */
int		ft_putnbr_u_fd(unsigned int n, int fd);
int		ft_putnbr_x_fd(unsigned int n, int fd);
int		ft_putnbr_x_up_fd(unsigned int n, int fd);

#endif