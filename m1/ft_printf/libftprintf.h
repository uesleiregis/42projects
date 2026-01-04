/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:12:28 by uregis-d          #+#    #+#             */
/*   Updated: 2025/11/25 16:18:09 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define FD 1

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/* Useful ft_printf functions */
int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

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
void	ft_putnbr_u_fd(unsigned int n, int fd);
void	ft_putnbr_x_fd(unsigned int n, int fd);
void	ft_putnbr_x_up_fd(unsigned int n, int fd);

#endif