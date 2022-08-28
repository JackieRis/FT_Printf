/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:34:06 by tnguyen-          #+#    #+#             */
/*   Updated: 2021/12/10 11:47:03 by tnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long int n, char *base, int fd, int *i)
{
	unsigned long int	nbase;

	nbase = ft_strlen(base);
	if (n >= nbase)
		ft_putnbr_base(n / nbase, base, fd, i);
	(*i) += ft_putchar_fd(base[n % nbase], fd);
}
