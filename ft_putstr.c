/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <ldauber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:24:04 by ldauber           #+#    #+#             */
/*   Updated: 2026/01/06 14:23:13 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_putstr(char *s)
{
	if (!s)
	{
		write(2, "(null)", 6);
		return (6);
	}
	write(2, s, ft_strlen(s));
	return (ft_strlen(s));
}
