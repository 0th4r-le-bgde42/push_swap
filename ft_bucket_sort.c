/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bucket_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschappe <mschappe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:45:11 by mschappe          #+#    #+#             */
/*   Updated: 2026/01/07 15:47:50 by mschappe         ###   ########.fr       */
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
    while (++i <= len / 2)
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
	i = -1;
	while (++i < len)
	{
		tmp = *a;
		while (tmp)
		{
			if (tmp->value == tab_index[i])
			{
				tmp->index = i;
				break ;
			}
			tmp = tmp->next;
		}
	}
}

void    ft_bucket_sort(t_stack **a, t_stack **b, t_tracking **track)
{
    ft_init_index(a, track);
    printf("%p\n", b);
	// calculer les nmbrs de buckets
	//insertions algo
}