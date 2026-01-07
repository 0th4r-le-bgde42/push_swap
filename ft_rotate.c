/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <ldauber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:09:31 by ldauber           #+#    #+#             */
/*   Updated: 2026/01/07 11:49:28 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	first = *stack;
	(*stack)->next->prev = NULL;
	*stack = (*stack)->next;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ft_ra(t_stack **stack_a, t_tracking **track)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
	(*track)->r[0] += 1;
	(*track)->total_ops += 1;
}

void	ft_rb(t_stack **stack_b, t_tracking **track)
{
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
	(*track)->r[1] += 1;
	(*track)->total_ops += 1;
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b, t_tracking **track)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
	(*track)->r[2] += 1;
	(*track)->total_ops += 1;
}
