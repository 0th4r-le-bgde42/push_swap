/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschappe <mschappe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:34:23 by mschappe          #+#    #+#             */
/*   Updated: 2026/01/14 15:29:47 by mschappe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_check_valid_input(char *s)
{
	if (ft_strcmp(s, "--bench") == 0)
		return (0);
	if (ft_strcmp(s, "--simple") == 0)
		return (0);
	if (ft_strcmp(s, "--medium") == 0)
		return (0);
	if (ft_strcmp(s, "--complex") == 0)
		return (0);
	if (ft_strcmp(s, "--adaptive") == 0)
		return (0);
	if (ft_isnum(s))
		return (0);
	return (1);
}

static	int	ft_check_bench(char *s, char *bench, t_tracking **track, int ac)
{
	if (ft_check_valid_input(s))
		return (1);
	if (ft_strcmp(s, bench) == 0)
	{
		(*track)->bench = 1;
		(*track)->nb_options += 1;
		if (ac == 2)
			return (1);
	}
	return (0);
}

static	int	ft_check_algo(char *s, t_tracking **track)
{
	if (ft_check_valid_input(s))
		return (1);
	if (ft_isnum(s))
		return (0);
	if (ft_strcmp(s, "--simple") == 0)
		(*track)->strat = "Simple";
	else if (ft_strcmp(s, "--medium") == 0)
		(*track)->strat = "Medium";
	else if (ft_strcmp(s, "--complex") == 0)
		(*track)->strat = "Complex";
	else if (ft_strcmp(s, "--adaptive") == 0)
		(*track)->strat = "Adaptive";
	(*track)->nb_options += 1;
	return (0);
}

static	int	ft_check_options_extend(char **av, t_tracking **track, int ac)
{
	if (ft_check_bench(av[1], "--bench", track, ac))
		return (1);
	if ((*track)->bench)
	{
		if (ft_strcmp(av[2], "--bench") == 0)
			return (1);
		if (ft_check_algo(av[2], track))
			return (1);
		if (ac == 3 && (*track)->nb_options == 2)
			return (1);
	}
	else
	{
		if (ft_check_algo(av[1], track))
			return (1);
		if (ac == 2 && (*track)->nb_options == 1)
			return (1);
		if ((*track)->nb_options == 1 && !ft_isnum(av[2]))
			return (1);
	}
	return (0);
}

void	ft_check_options(char **av, t_tracking **track, int ac)
{
	if (ft_check_options_extend(av, track, ac))
	{
		ft_free_split(av);
		ft_error(track);
	}
}
