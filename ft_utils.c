/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <ldauber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:17:35 by mschappe          #+#    #+#             */
/*   Updated: 2026/01/07 11:47:56 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *s)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i])
	{
		res *= 10;
		res += s[i] - 48;
		i++;
	}
	return (res * sign);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	print_status(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	tmp = a;
	ft_printf("\n--- ÉTAT DES PILES ---\n");
	ft_printf("A: ");
	while (tmp)
	{
		ft_printf("[%d]", tmp->value);
		if (tmp->next)
			ft_printf(" -> ");
		tmp = tmp->next;
	}
	ft_printf("\nB: ");
	tmp = b;
	while (tmp)
	{
		ft_printf("[%d]", tmp->value);
		if (tmp->next)
			ft_printf(" -> ");
		tmp = tmp->next;
	}
	ft_printf("\n----------------------\n");
}

int	ft_isnum(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_dup(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->value == new->value)
		{
			free(new);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
