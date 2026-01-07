/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <ldauber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 10:01:42 by ldauber           #+#    #+#             */
/*   Updated: 2026/01/07 11:08:51 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next || !stack)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack = second;
}

void	ft_sa(t_stack **stack_a, t_tracking **track)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
	(*track)->s[0] += 1;
	(*track)->total_ops += 1;
}

void	ft_sb(t_stack **stack_b, t_tracking **track)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
	(*track)->s[1] += 1;
	(*track)->total_ops += 1;
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b, t_tracking **track)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
	(*track)->s[2] += 1;
	(*track)->total_ops += 1;
}
