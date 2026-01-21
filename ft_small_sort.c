/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschappe <mschappe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:51:52 by ldauber           #+#    #+#             */
/*   Updated: 2026/01/21 10:39:59 by mschappe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_sort_two(t_stack **a, t_tracking **track)
{
	if ((*track)->disorder == 1.00)
		ft_sa(a, track);
}

static	void	ft_index2(t_stack **a, t_tracking **track, int index)
{
	if (index == 0)
		ft_ra(a, track);
	else
	{
		ft_sa(a, track);
		ft_rra(a, track);
	}
}

static	void	ft_sort_three(t_stack **a, t_tracking **track)
{
	t_stack	*mid;

	ft_init_index(a, track);
	mid = (*a)->next;
	if ((*a)->index == 0 && mid->index == 2)
	{
		ft_ra(a, track);
		ft_sa(a, track);
		ft_rra(a, track);
	}
	else if ((*a)->index == 1)
	{
		if (mid->index == 0)
			ft_sa(a, track);
		else
			ft_rra(a, track);
	}
	else if ((*a)->index == 2)
		ft_index2(a, track, mid->index);
}

void	ft_small_sort(t_stack **a, t_stack **b, t_tracking **track)
{
	b = NULL;
	if (ft_str_stack_len(a) == 2)
		ft_sort_two(a, track);
	if (ft_str_stack_len(a) == 3)
		ft_sort_three(a, track);
}
