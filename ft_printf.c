/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnguyen- <tnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:21:28 by tnguyen-          #+#    #+#             */
/*   Updated: 2021/12/09 18:53:54 by tnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	checklist(int fd, va_list params, const char *format)
{
	int		i;

	i = 0;
	if (format[1] == 'i' || format[1] == 'd')
		ft_putnbr(va_arg(params, int), &i, fd);
	else if (format[1] == 'c')
		i = ft_putchar_fd(va_arg(params, int), fd);
	else if (format[1] == 's')
		i = ft_putstr_fd(va_arg(params, char *), fd);
	else if (format[1] == '%')
		i = ft_putchar_fd('%', fd);
	else if (format[1] == 'x')
		ft_putnbr_base(va_arg(params, unsigned int), "0123456789abcdef", fd, &i);
	else if (format[1] == 'X')
		ft_putnbr_base(va_arg(params, unsigned int), "0123456789ABCDEF", fd, &i);
	else if (format[1] == 'u')
		ft_putnbr_base(va_arg(params, unsigned int), "0123456789", fd, &i);
	else if (format[1] == 'p')
	{
		i = ft_putstr_fd("0x", fd);
		ft_putnbr_base(va_arg(params, unsigned long int), "0123456789abcdef", fd, &i);
	}
	return (i);
}

int	ft_printf(int fd, const char *format, ...)
{
	int		i;
	int		count;
	va_list	params;

	i = -1;
	count = 0;
	va_start(params, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				return (count);
			count += checklist(fd, params, &format[i]);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], fd);
			count++;
		}
	}
	va_end(params);
	return (count);
}
