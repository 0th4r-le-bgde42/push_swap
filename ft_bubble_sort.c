/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <ldauber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:32:09 by ldauber           #+#    #+#             */
/*   Updated: 2026/01/07 11:50:58 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_bubble_swap(t_stack **a, t_stack **b, int size,
	t_tracking **track)
{
	int	i;

	i = 0;
	ft_pb(a, b, track);
	while (i < size)
	{
		if ((*a)->value < (*b)->value)
		{
			ft_pb(a, b, track);
			ft_sb(b, track);
			if (*a != NULL)
			{
				ft_pa(b, a, track);
				ft_ra(a, track);
			}
		}
		else
			ft_ra(a, track);
		i++;
	}
}

void	ft_bubble_sort(t_stack **a, t_stack **b, int size, t_tracking **track)
{
	int	n;

	n = size - 1;
	if (size == 1)
		return ;
	while (*a)
	{
		ft_bubble_swap(a, b, n, track);
		n--;
	}
	while (*b)
		ft_pa(b, a, track);
}
