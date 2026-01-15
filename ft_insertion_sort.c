/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <ldauber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:45:34 by ldauber           #+#    #+#             */
/*   Updated: 2026/01/14 15:01:08 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_min_pos(t_stack **stack)
{
	t_stack	*curr;
	int		min_val;
	int		min_pos;
	int		pos;

	if (!stack || !*stack)
		return (0);
	curr = *stack;
	min_val = curr->value;
	min_pos = 0;
	pos = 0;
	while (curr)
	{
		if (curr->value < min_val)
		{
			min_val = curr->value;
			min_pos = pos;
		}
		pos++;
		curr = curr->next;
	}
	return (min_pos);
}

void	ft_insertion_sort(t_stack **a, t_stack **b, t_tracking **track)
{
	int	pos;
	int	size;

	if (ft_str_stack_len(a) == 1)
		return ;	
	while (*a)
	{
		pos = ft_min_pos(a);
		size = ft_str_stack_len(a);
		if (pos <= size / 2)
		{
			while (pos--)
				ft_ra(a, track);
		}
		else
		{
			while (pos++ < size)
				ft_rra(a, track);
		}
		ft_pb(a, b, track);
	}
	while (*b)
		ft_pa(b, a, track);
}
