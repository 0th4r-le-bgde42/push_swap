/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <ldauber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:14:57 by ldauber           #+#    #+#             */
/*   Updated: 2026/01/07 11:02:41 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putfloat(double n)
{
	long long	int_ft_part;
	double		dec_ft_part;
	int			i;
	int			len;

	len = 0;
	if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	n += 0.005;
	int_ft_part = (long long)n;
	len += ft_putnbr(int_ft_part);
	len += ft_putchar('.');
	i = -1;
	dec_ft_part = n - (double)int_ft_part;
	while (++i < 2)
	{
		dec_ft_part *= 10;
		len += write(2, &"0123456789"[(int)dec_ft_part % 10], 1);
		dec_ft_part -= (int)dec_ft_part;
	}
	return (len);
}
