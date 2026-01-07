/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <ldauber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:34:23 by mschappe          #+#    #+#             */
/*   Updated: 2026/01/07 11:03:02 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_check_valid_input(char *s, t_tracking **track)
{
	if (ft_strcmp(s, "--bench") == 0)
		return ;
	if (ft_strcmp(s, "--simple") == 0)
		return ;
	if (ft_strcmp(s, "--medium") == 0)
		return ;
	if (ft_strcmp(s, "--complex") == 0)
		return ;
	if (ft_strcmp(s, "--adaptive") == 0)
		return ;
	if (ft_isnum(s))
		return ;
	ft_error(track);
}

static	void	ft_check_bench(char *s, char *bench, t_tracking **track, int ac)
{
	ft_check_valid_input(s, track);
	if (ft_strcmp(s, bench) == 0)
	{
		(*track)->bench = 1;
		(*track)->nb_options += 1;
		if (ac == 2)
			ft_error(track);
	}
}

static	void	ft_check_algo(char *s, t_tracking **track)
{
	ft_check_valid_input(s, track);
	if (ft_isnum(s))
		return ;
	if (ft_strcmp(s, "--simple") == 0)
		(*track)->strat = "Simple";
	else if (ft_strcmp(s, "--medium") == 0)
		(*track)->strat = "Medium";
	else if (ft_strcmp(s, "--complex") == 0)
		(*track)->strat = "Complex";
	else if (ft_strcmp(s, "--adaptive") == 0)
		(*track)->strat = "Adaptive";
	(*track)->nb_options += 1;
}

void	ft_check_options(char **av, t_tracking **track, int ac)
{
	ft_check_bench(av[1], "--bench", track, ac);
	if ((*track)->bench)
	{
		if (ft_strcmp(av[2], "--bench") == 0)
			ft_error(track);
		ft_check_algo(av[2], track);
		if (ac == 3 && (*track)->nb_options == 2)
			ft_error(track);
	}
	else
	{
		ft_check_algo(av[1], track);
		if (ac == 2 && (*track)->nb_options == 1)
			ft_error(track);
		if ((*track)->nb_options == 1 && !ft_isnum(av[2]))
			ft_error(track);
	}
}
