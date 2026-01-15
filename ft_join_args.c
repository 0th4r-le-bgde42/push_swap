/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <ldauber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:10:54 by mschappe          #+#    #+#             */
/*   Updated: 2026/01/14 14:48:22 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_total_len(int ac, char **av)
{
	int	len;
	int	i;
	int	count;

	len = 0;
	count = 0;
	i = 0;
	while (count < ac)
	{
		while (av[count][i] != '\0')
			i++;
		len += i;
		i = 0;
		count++;
	}
	return (len + ac);
}

char	*ft_join_args(int ac, char **av, t_tracking **track)
{
	char	*res;
	int		count;
	int		i;
	int		j;

	res = malloc((ft_total_len(ac, av) + 1) * sizeof(char));
	if (!res)
		ft_error(track);
	count = 0;
	i = -1;
	j = 0;
	while (count < ac)
	{
		while (av[count][++i] != '\0')
		{
			res[j] = av[count][i];
			j++;
		}
		res[j] = ' ';
		j++;
		i = -1;
		count++;
	}
	res[j] = '\0';
	return (res);
}
