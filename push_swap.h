/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <ldauber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 11:44:45 by ldauber           #+#    #+#             */
/*   Updated: 2026/01/12 11:10:43 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libftprintf.h"

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h> // SUPP

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_tracking
{
	int		bench;
	int		nb_options;
	double	disorder;
	char	*strat;
	char	*form;
	int		total_ops;
	int		s[3];
	int		p[2];
	int		r[3];
	int		rr[3];
}	t_tracking;

void	print_status(t_stack *a, t_stack *b);

void	ft_sa(t_stack **stack_a, t_tracking **track);
void	ft_sb(t_stack **stack_b, t_tracking **track);
void	ft_ss(t_stack **stack_a, t_stack **stack_b, t_tracking **track);
void	ft_pa(t_stack **b, t_stack **a, t_tracking **track);
void	ft_pb(t_stack **a, t_stack **b, t_tracking **track);
void	ft_ra(t_stack **stack_a, t_tracking **track);
void	ft_rb(t_stack **stack_b, t_tracking **track);
void	ft_rr(t_stack **stack_a, t_stack **stack_b, t_tracking **track);
void	ft_rra(t_stack **stack_a, t_tracking **track);
void	ft_rrb(t_stack **stack_b, t_tracking **track);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b, t_tracking **track);
void	ft_stack_add_back(t_stack **stack, t_stack *new, t_tracking **track);
void	ft_init_track(t_tracking **track);
void	ft_bench(t_tracking **track);
void	ft_check_options(char **av, t_tracking **track, int ac);
void	ft_error(t_tracking **track);
void	ft_free_stack(t_stack **stack);
void	ft_insertion_sort(t_stack **a, t_stack **b, t_tracking **track);
void	ft_bucket_sort(t_stack **a, t_stack **b, t_tracking **track);
void	ft_adaptive(t_stack **a, t_stack **b, t_tracking **track);
long	ft_atoi(char *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_isnum(char *s);
int		ft_str_stack_len(t_stack **stack);
int		ft_is_dup(t_stack **stack, t_stack *new);
int		ft_sqrt(int n);
t_stack	*ft_new_node(int val);

#endif
