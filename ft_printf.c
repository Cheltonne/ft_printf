/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <chajax@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:30:17 by chajax            #+#    #+#             */
/*   Updated: 2021/11/05 16:02:52 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_lower_hexa(unsigned long nb)
{
	int		len;
	char	*hexa;
	char	*ret;

	hexa = hexa_conv(nb, 'x');
	ret = reverse_string(hexa);
	free(hexa);
	len = ft_putstr(ret);
	if (!len)
		len = ft_putchar('0');
	free(ret);
	return (len);
}

int	put_upper_hexa(unsigned long nb)
{
	int		len;
	char	*hexa;
	char	*ret;

	hexa = hexa_conv(nb, 'X');
	ret = reverse_string(hexa);
	free(hexa);
	len = ft_putstr(ret);
	if (!len)
		len = ft_putchar('0');
	free(ret);
	return (len);
}

int	put_adr(uintptr_t adr)
{
	int		len;
	char	*adrr;
	char	*ret;

	len = 0;
	adrr = NULL;
	ret = NULL;
	if (!adr)
		return (ft_putstr("0x0"));
	adrr = hexa_conv(adr, 'p');
	ret = reverse_string(adrr);
	free(adrr);
	len = ft_putstr("0x");
	len += ft_putstr(ret);
	free(ret);
	return (len);
}

int	format_check(char c, va_list a_list)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(a_list, int));
	else if (c == 's')
		len = ft_putstr(va_arg(a_list, char *));
	else if (c == 'p')
		len = put_adr(va_arg(a_list, uintptr_t));
	else if (c == 'd' || c == 'i')
		len = ft_putnbr_fd(va_arg(a_list, int), 1);
	else if (c == 'u')
		len = ft_putnbr_fd(va_arg(a_list, unsigned int), 1);
	else if (c == 'x')
		len = put_lower_hexa(va_arg(a_list, unsigned long));
	else if (c == 'X')
		len = put_upper_hexa(va_arg(a_list, unsigned long));
	else if (c == '%')
	{
		len = ft_putchar('%');
		len = 1;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	a_list;

	len = 0;
	if (!format)
		return (0);
	va_start(a_list, format);
	while (*format)
	{
		if (*format == '%' && ft_strchr("cspiduxX%", *(format + 1)))
		{
			len += format_check(*(format + 1), a_list);
			format += 2;
		}
		else
			len += ft_putchar(*format++);
	}
	va_end(a_list);
	return (len);
}
