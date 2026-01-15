/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschappe <mschappe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:36:00 by ldauber           #+#    #+#             */
/*   Updated: 2026/01/12 13:36:26 by mschappe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_compute_disorder(t_stack *a, t_tracking **track)
{
	t_stack	*i;
	t_stack	*j;
	int		mistakes;
	int		total_ft_pairs;

	if (!a || !a->next)
		return ;
	mistakes = 0;
	total_ft_pairs = 0;
	i = a;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			total_ft_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	(*track)->disorder = ((double)mistakes / (double)total_ft_pairs);
}

void	ft_adaptive(t_stack **a, t_stack **b, t_tracking **track)
{
	ft_compute_disorder(*a, track);
	if ((*track)->disorder < 0.2)
	{
		(*track)->form = "O(n²)";
		ft_insertion_sort(a, b, track);
	}
	else if ((*track)->disorder < 0.5)
	{
		(*track)->form = "O(n√n)";
		ft_bucket_sort(a, b, track);
	}
	else if ((*track)->disorder >= 0.5)
	{
		(*track)->form = "O(n log n)";
		ft_radix(a, b, track);
	}
}
