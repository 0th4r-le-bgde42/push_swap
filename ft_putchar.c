/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <ldauber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:48:14 by ldauber           #+#    #+#             */
/*   Updated: 2026/01/06 14:22:26 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(unsigned int c)
{
	unsigned char	a;

	a = (unsigned char)c;
	write(2, &a, 1);
	return (1);
}

/*int main()
{
	int a = 122;
	ft_putchar(a);
	return (0);
}*/
