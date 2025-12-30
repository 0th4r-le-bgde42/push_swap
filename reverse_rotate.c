/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:20:33 by ldauber           #+#    #+#             */
/*   Updated: 2025/12/30 15:21:07 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_stack **stack)
{
	t_stack *tmp;
	t_stack *first;
	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	first = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	(*stack)->prev = tmp;
	tmp->prev->next = NULL;
	*stack = (*stack)->next;
}

void rra()
{
}

void rrb()
{
}

void rrr()
{
}
