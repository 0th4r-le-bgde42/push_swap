/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <ldauber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:27:51 by mschappe          #+#    #+#             */
/*   Updated: 2026/01/14 14:46:50 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	*ft_init_tab(t_stack **a, t_tracking **track, int len)
{
	int		*tab_index;
	t_stack	*tmp_a;
	int		i;

	tab_index = malloc(len * sizeof(int));
	if (!tab_index)
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
	int	i;
	int	j;
	int	tmp;

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

void	ft_init_index(t_stack **a, t_tracking **track)
{
	int		*tab_index;
	int		len;
	int		i;
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
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		i = 0;
		tmp = tmp->next;
	}
	free(tab_index);
}
