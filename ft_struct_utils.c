/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <ldauber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:36:34 by mschappe          #+#    #+#             */
/*   Updated: 2026/01/14 14:47:19 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*TRACK*/
void	ft_init_track(t_tracking **track)
{
	int	i;

	i = -1;
	(*track)->bench = 0;
	(*track)->nb_options = 0;
	(*track)->disorder = 0.0;
	(*track)->strat = "Adaptive";
	(*track)->total_ops = 0;
	while (++i < 3)
	{
		if (i < 2)
			(*track)->p[i] = 0;
		(*track)->s[i] = 0;
		(*track)->r[i] = 0;
		(*track)->rr[i] = 0;
	}
}

/*STACK*/
t_stack	*ft_new_node(int val)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = val;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_stack_add_back(t_stack **stack, t_stack *new,
				t_tracking **track, char **av)
{
	t_stack	*last;

	if (!stack || !new || ft_is_dup(stack, new))
	{
		ft_free_split(av);
		ft_free_stack(stack);
		ft_error(track);
	}
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}

int	ft_str_stack_len(t_stack **stack)
{
	int		size;
	t_stack	*tmp;

	if (!stack)
		return (0);
	size = 0;
	tmp = *stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
