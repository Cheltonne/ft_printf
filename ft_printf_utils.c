/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajax <chajax@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 22:07:40 by chajax            #+#    #+#             */
/*   Updated: 2021/11/03 13:03:03 by chajax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		ft_putchar(*str++);
		len++;
	}
	return (len);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (*str++)
		i++;
	return (i);
}

char	*reverse_string(char *str)
{
	size_t	i;
	int		len;
	char	*ret;

	if (!str)
		return (NULL);
	i = 0;
	len = ft_strlen(str);
	ret = malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	while (i < ft_strlen(str))
	{
		ret[i] = str[len - 1];
		i++;
		len--;
	}
	return (ret);
}

char	*hexa_conv(uintptr_t nb, char precision)
{
	long	remainder;
	char	*hexa;
	size_t	i;

	i = 0;
	hexa = malloc(17);
	if (!hexa)
		return (NULL);
	if (precision == 'x' || precision == 'X')
		nb = (unsigned int)(nb);
	while (nb)
	{
		remainder = nb % 16;
		if (remainder < 10)
			hexa[i++] = 48 + remainder;
		else if (nb >= 10 && (precision == 'x' || precision == 'p'))
			hexa[i++] = 87 + remainder;
		else
			hexa[i++] = 55 + remainder;
		nb /= 16;
	}
	hexa[i] = '\0';
	return (hexa);
}
