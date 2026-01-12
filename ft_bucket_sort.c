/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bucket_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschappe <mschappe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:45:11 by mschappe          #+#    #+#             */
/*   Updated: 2026/01/12 11:40:09 by mschappe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  int *ft_init_tab(t_stack **a, t_tracking **track, int len)
{
	int     *tab_index;
    t_stack *tmp_a;
    int     i;
	
    tab_index = malloc(len * sizeof(int));
    if(!tab_index)
    {
        ft_free_stack(a);
        ft_error(track);
    }
    tmp_a = *a;
    i = -1;
    while (++i < len)
    {
        tab_index[i] = tmp_a->value;
        tmp_a = tmp_a->next;
    }
	return (tab_index);
}
static	void	ft_sort_tab(int *tab_index, int len)
{
	int i;
	int j;
	int tmp;

	tmp = 0;
    i = -1;
    while (++i < len)
    {
        j = i - 1;
        while (++j < len)
        {
            if (tab_index[j] < tab_index[i])
            {
                tmp = tab_index[i];
                tab_index[i] = tab_index[j];
                tab_index[j] = tmp;
            }
        }
    }
}

static  void    ft_init_index(t_stack **a, t_tracking **track)
{
    int     *tab_index;
    int     len;
    int     i;
	t_stack	*tmp;

    len = ft_str_stack_len(a);
    tab_index = ft_init_tab(a, track, len);
	ft_sort_tab(tab_index, len);
	i = 0;
	tmp = *a;
	while (tmp)
	{
		while (i < len)
		{
			if (tmp->value == tab_index[i])
				tmp->index = i;
			i++;
		}
		i = 0;
		tmp = tmp->next;
	}
}
// pousser les chunks dans b et tourner pour push dans a du plus petit au plus grand
void    ft_bucket_sort(t_stack **a, t_stack **b, t_tracking **track)
{
    int	len;
    int	count;
	int	range;
    int current_range;
    int prev_range;
	int	max_index;
	int	min_index;
	int	tmp_index;

    len = ft_str_stack_len(a);
    if (len == 1)
        return ;
    ft_init_index(a, track);
	count = 0;
	range = ft_sqrt(len);
    if ((len - range) < 0)
        current_range = len;
    else
        current_range = len - range;
    prev_range = len;
	min_index = len - 1;
	max_index = 0;
	tmp_index = -1;
	while (count < len)
	{
        if ((*a)->index >= current_range && (*a)->index < prev_range)
        {
			if ((*a)->index > max_index)
				max_index = (*a)->index;
			if ((*a)->index < min_index)
				min_index = ((*a)->index);
			ft_pb(a, b, track);
			count ++;
			if (ft_str_stack_len(b) == range || count == len)
			{
				if (count > range)
					while ((*a)->index != tmp_index)
						ft_ra(a, track);
				while(*b)
				{
					if ((*b)->index == max_index)
					{
						ft_pa(b, a, track);
						max_index--;
					}
					ft_rb(b, track);
				}
				prev_range = current_range;
				if (current_range - range < 0)
					current_range = 0;
				else
					current_range -= range;
				max_index = 0;
				tmp_index = min_index;
			}
        }
		else
			ft_ra(a, track);
	}
	print_status(*a,*b);
}
