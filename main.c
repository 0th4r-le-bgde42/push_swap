/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschappe <mschappe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 08:25:47 by ldauber           #+#    #+#             */
/*   Updated: 2026/01/14 15:29:58 by mschappe         ###   ########.fr       */
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
			ft_free_split(av);
			ft_free_stack(a);
			ft_error(track);
		}
		val = ft_atoi(av[i]);
		if (val > 2147483647 || val < -2147483648)
		{
			ft_free_split(av);
			ft_free_stack(a);
			ft_error(track);
		}
		ft_stack_add_back(a, ft_new_node((int) val), track, av);
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
		ft_radix(a, b, track);
	else
		ft_adaptive(a, b, track);
	if ((*track)->bench)
		ft_bench(track);
}

static	int	ft_new_ac(char **new_av)
{
	int	new_ac;

	new_ac = 0;
	while (new_av[new_ac])
		new_ac++;
	return (new_ac);
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_tracking	*track;
	char		*join_av;
	char		**new_av;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	track = malloc(sizeof(t_tracking));
	if (!track)
		return (0);
	ft_init_track(&track);
	join_av = ft_join_args(ac, av, &track);
	new_av = ft_split(join_av, ' ', &track);
	ft_check_options(new_av, &track, ft_new_ac(new_av));
	ft_init_stack(&a, &track, ft_new_ac(new_av), new_av);
	ft_selector(&a, &b, &track);
	print_status(a, b);
	ft_free_split(new_av);
	free(track);
	ft_free_stack(&a);
	return (0);
}
