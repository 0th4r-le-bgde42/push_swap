/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <ldauber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:33:43 by mschappe          #+#    #+#             */
/*   Updated: 2026/01/15 10:45:22 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_radix(t_stack **a, t_stack **b, t_tracking **track)
{
	int	len;
	int	max_bits;
	int	i;
	int	j;

	ft_init_index(a, track);
	len = ft_str_stack_len(a);
	max_bits = 0;
	while (((len - 1) >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < len)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ft_ra(a, track);
			else
				ft_pb(a, b, track);
		}
		while (*b)
			ft_pa(b, a, track);
	}
}
