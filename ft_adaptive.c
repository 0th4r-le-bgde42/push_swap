/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <ldauber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:36:00 by ldauber           #+#    #+#             */
/*   Updated: 2026/01/15 10:44:49 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_adaptive(t_stack **a, t_stack **b, t_tracking **track)
{
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
