/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <ldauber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:32:09 by ldauber           #+#    #+#             */
/*   Updated: 2026/01/05 16:17:22 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void bubble_swap(t_stack **a, t_stack **b, int size, t_tracking **track)
{
	(*track)->disorder = 0.0;
	int i;

	i = 0;
	pb(a, b);
	while (i < size)
	{
		if ((*a)->next == NULL)
		{
			pb(a, b);
			return ;
		}
		if ((*a)->value < (*b)->value)
		{
			pb(a, b);
			sb(b);
			pa(b, a);
			ra(a);
		}
		else
			ra(a);
		i++;
	}
}

void	bubble_sort(t_stack **a, t_stack **b, int size, t_tracking **track)
{
	int n;
	
	n = size;
	while (n > 0 && *a)
	{
		bubble_swap(a, b, n, track);
		n--;
	}
	while (*b)
		pa(b, a);
}
