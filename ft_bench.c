/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <ldauber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:10:09 by ldauber           #+#    #+#             */
/*   Updated: 2026/01/14 14:52:37 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_strat(t_tracking **track)
{
	if (ft_strcmp((*track)->strat, "Simple") == 0)
		ft_printf("[bench] strategy: Simple / O(n²)\n");
	else if (ft_strcmp((*track)->strat, "Medium") == 0)
		ft_printf("[bench] strategy: Medium / O(n√n)\n");
	else if (ft_strcmp((*track)->strat, "Complex") == 0)
		ft_printf("[bench] strategy: Complex / O(n log n)\n");
	else if (ft_strcmp((*track)->strat, "Adaptive") == 0)
		ft_printf("[bench] strategy: Adaptive / %s\n", (*track)->form);
}

void	ft_bench(t_tracking **track)
{
	ft_printf("\n[bench] disorder: %f%%\n", (*track)->disorder * 100);
	ft_strat(track);
	ft_printf("[bench] total_ops: %d\n", (*track)->total_ops);
	ft_printf("[bench] sa: %d sb: %d ss: %d ", (*track)->s[0], (*track)->s[1],
		(*track)->s[2]);
	ft_printf("pa: %d pb: %d\n", (*track)->p[0], (*track)->p[1]);
	ft_printf("[bench] ra: %d rb: %d rr: %d ", (*track)->r[0], (*track)->r[1],
		(*track)->r[2]);
	ft_printf("rra: %d rrb: %d rrr: %d\n\n", (*track)->rr[0],
		(*track)->rr[1], (*track)->rr[2]);
}
