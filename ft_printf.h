/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <chajax@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:31:21 by chajax            #+#    #+#             */
/*   Updated: 2021/11/05 15:56:59 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>

char	*ft_strchr(char *s, int c);
int		ft_putchar(char c);
int		ft_putstr(char *str);
size_t	ft_strlen(char *str);
char	*reverse_string(char *str);
char	*hexa_conv(uintptr_t nb, char precision);
int		ft_putnbr_fd(long n, int fd);
int		put_lower_hexa(unsigned long nb);
int		put_upper_hexa(unsigned long nb);
int		put_adr(uintptr_t adr);
int		format_check(char c, va_list b_list);
int		ft_printf(const char *format, ...);
#endif
