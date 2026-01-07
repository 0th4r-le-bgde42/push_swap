/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <ldauber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:20:33 by ldauber           #+#    #+#             */
/*   Updated: 2026/01/07 11:49:20 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_reverse_ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	first = *stack;
	while (last->next != NULL)
		last = last->next;
	if (last->prev)
		last->prev->next = NULL;
	last->next = first;
	first->prev = last;
	last->prev = NULL;
	*stack = last;
}

void	ft_rra(t_stack **stack_a, t_tracking **track)
{
	ft_reverse_ft_rotate(stack_a);
	write(1, "rra\n", 4);
	(*track)->rr[0] += 1;
	(*track)->total_ops += 1;
}

void	ft_rrb(t_stack **stack_b, t_tracking **track)
{
	ft_reverse_ft_rotate(stack_b);
	write(1, "rrb\n", 4);
	(*track)->rr[1] += 1;
	(*track)->total_ops += 1;
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b, t_tracking **track)
{
	ft_reverse_ft_rotate(stack_a);
	ft_reverse_ft_rotate(stack_b);
	write(1, "rrr\n", 4);
	(*track)->rr[2] += 1;
	(*track)->total_ops += 1;
}
