/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 13:07:58 by ldauber           #+#    #+#             */
/*   Updated: 2026/01/05 10:24:32 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	if (!dst || !*dst)
	{
		*dst = *src;
		(*src)->next->prev = NULL;
		*src = (*src)->next;
		(*dst)->next = NULL;
	}
	else
	{
		tmp = *src;
		if ((*src)->next)
			(*src)->next->prev = NULL;
		*src = (*src)->next;
		(*dst)->prev = tmp;
		tmp->next = *dst;
		*dst = tmp;
	}
}

void	pa(t_stack **b, t_stack **a)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
