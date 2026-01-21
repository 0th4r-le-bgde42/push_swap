/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bucket_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <ldauber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:45:11 by mschappe          #+#    #+#             */
/*   Updated: 2026/01/15 10:47:01 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_position(t_stack **stack, int index)
{
	t_stack	*tmp;
	int		res;

	tmp = *stack;
	res = 0;
	while (tmp->index != index)
	{
		res++;
		tmp = tmp->next;
	}
	return (res);
}

static	void	ft_in_range(t_stack **a, t_stack **b,
		t_tracking **track, t_bucket *bucket)
{
	if (bucket->count > bucket->range)
		while ((*a)->index != bucket->tmp_index)
			ft_ra(a, track);
	while (*b)
	{
		if (ft_position(b, bucket->max_index) < (ft_str_stack_len(b) / 2))
			while ((*b)->index != bucket->max_index)
				ft_rb(b, track);
		else
			while ((*b)->index != bucket->max_index)
				ft_rrb(b, track);
		bucket->max_index--;
		ft_pa(b, a, track);
	}
	bucket->prev_range = bucket->current_range;
	if (bucket->current_range - bucket->range < 0)
		bucket->current_range = 0;
	else
		bucket->current_range -= bucket->range;
	bucket->max_index = 0;
	bucket->tmp_index = bucket->min_index;
}

static	void	ft_bucket_sort_2(t_stack **a, t_stack **b,
		t_tracking **track, t_bucket *bucket)
{
	if ((*a)->index >= bucket->current_range
		&& (*a)->index < bucket->prev_range)
	{
		if ((*a)->index >= bucket->max_index)
			bucket->max_index = (*a)->index;
		if ((*a)->index <= bucket->min_index)
			bucket->min_index = ((*a)->index);
		ft_pb(a, b, track);
		if ((*b)->index < (bucket->current_range + (bucket->range / 2)))
			ft_rb(b, track);
		bucket->count ++;
		if (ft_str_stack_len(b) == bucket->range
			|| bucket->count == bucket->len)
			ft_in_range(a, b, track, bucket);
	}
	else
		ft_rra(a, track);
}

void	ft_bucket_sort(t_stack **a, t_stack **b, t_tracking **track)
{
	t_bucket	bucket;

	bucket.len = ft_str_stack_len(a);
	if (bucket.len == 1)
		return ;
	ft_init_index(a, track);
	bucket.count = 0;
	bucket.range = (bucket.len / 10) + (bucket.len / 100) + 7;
	if (bucket.range > bucket.len)
	{
		bucket.current_range = 0;
		bucket.range = bucket.len;
	}
	else
		bucket.current_range = bucket.len - bucket.range;
	bucket.prev_range = bucket.len;
	bucket.max_index = 0;
	bucket.min_index = bucket.len - 1;
	bucket.tmp_index = -1;
	while (bucket.count < bucket.len)
		ft_bucket_sort_2(a, b, track, &bucket);
}
