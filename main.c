/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <ldauber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 08:25:47 by ldauber           #+#    #+#             */
/*   Updated: 2026/01/12 11:10:04 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static	void	ft_selector(t_stack **a, t_stack **b, t_tracking **track)
{
	if (ft_strcmp((*track)->strat, "Simple") == 0)
		ft_insertion_sort(a, b, track);
	else if (ft_strcmp((*track)->strat, "Medium") == 0)
		ft_bucket_sort(a, b, track);
	else if (ft_strcmp((*track)->strat, "Complex") == 0)
		ft_printf("Complex algo\n");
	else
		ft_adaptive(a, b, track);
	if ((*track)->bench)
		ft_bench(track);
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
	ft_selector(&a, &b, &track);
	free(track);
	ft_free_stack(&a);
	return (0);
}
