/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <ldauber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 08:25:47 by ldauber           #+#    #+#             */
/*   Updated: 2026/01/07 16:01:47 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Malloc sur var track et dans ft_ft_new_node sur var node//

static	void	ft_compute_disorder(t_stack **stack, t_tracking **track)
{
	t_stack	*i;
	t_stack	*j;
	int	mistakes;
	int	total_ft_pairs;

	if (!stack || !(*stack)->next)
		return ;
	mistakes = 0;
	total_ft_pairs = 0;
	i = *stack;
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
	(*track)->disorder = (double)((mistakes / total_ft_pairs) * 100);
}

static	void	ft_init_stack(t_stack **a, t_tracking **track,
	int ac, char **av)
{
	int		i;
	long	val;

	i = (*track)->nb_options + 1;
	while (i < ac)
	{
		if (!ft_isnum(av[i]))
		{
			ft_free_stack(a);
			ft_error(track);
		}
		val = ft_atoi(av[i]);
		if (val > 2147483647 || val < -2147483648)
		{
			ft_free_stack(a);
			ft_error(track);
		}
		ft_stack_add_back(a, ft_new_node((int) val), track);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_tracking	*track;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	track = malloc(sizeof(t_tracking));
	if (!track)
		return (0);
	ft_init_track(&track);
	ft_check_options(av, &track, ac);
	ft_init_stack(&a, &track, ac, av);
	ft_insertion_sort(&a, &b, &track);
	//ft_bubble_sort(&a, &b, ft_str_stack_len(&a), &track);
	ft_compute_disorder(&a, &track);
	print_status(a, b);
	if (track->bench == 1)
		ft_bench(&track);
	free(track);
	ft_free_stack(&a);
	return (0);
}
