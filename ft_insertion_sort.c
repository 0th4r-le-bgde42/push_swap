/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <ldauber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:45:34 by ldauber           #+#    #+#             */
/*   Updated: 2026/01/07 15:56:29 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*SI ON A LA FORCE, FAIRE COMME NICO*/

#include "push_swap.h"

 static	int	ft_count(t_stack **b, int higher)
{
	t_stack *tmp;
	int count;

	count = 0;
	tmp = *b;
	while (tmp->value != higher)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
} 

static void ft_magnet(int *higher, int *lower, t_stack **b)
{
	int tmp;
	t_stack *tmpb;

	tmp = 0;
	tmpb = *b;
	while (tmpb)
	{
		if (tmpb->value > tmp)
			tmp = tmpb->value;
		tmpb = tmpb->next;
	}
	*higher = tmp;
	tmpb = *b;
	while (tmpb)
	{
		if (tmpb->value < tmp)
			tmp = tmpb->value;
		tmpb = tmpb->next;
	}
	*lower = tmp;
}

static	void	ft_insertion_swap(t_stack **a, t_stack **b, t_tracking **track)
{
	static	int	higher;
	static	int	lower;

	ft_pb(a, b, track);
	ft_magnet(&higher, &lower, b);	
	if ((*b)->next)
	{
		while ((*b)->value < (*b)->next->value)
		{
			if ((*b)->next->value == higher && (*b)->value == lower)
				break ;
			ft_sb(b, track);
			if (ft_str_stack_len(b) == 2)
				break ;
			ft_rb(b, track);
		}
	}
	 if ((ft_count(b, higher) >= ft_str_stack_len(b) / 2))
		while ((*b)->value != higher)
			ft_rb(b, track);
	else
		while ((*b)->value != higher)
			ft_rrb(b, track); 
}

void	ft_insertion_sort(t_stack **a, t_stack **b, t_tracking **track)
{
	if (ft_str_stack_len(a) == 1)
		return ;
	while (*a)
		ft_insertion_swap(a, b, track);
	while (*b)
		ft_pa(b, a, track);
}
