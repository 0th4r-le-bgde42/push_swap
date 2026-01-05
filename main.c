/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <ldauber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 08:25:47 by ldauber           #+#    #+#             */
/*   Updated: 2026/01/05 15:48:44 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

// Utilitaire pour créer un nouveau noeud
t_stack	*new_node(int val)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = val;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

// Fonction d'affichage avancée pour vérifier l'intégrité de la liste
/*void	print_status(t_stack *a, t_stack *b)
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
}*/

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}

int	ft_atoi(char *s)
{
	int	i;
	int	res;
	int	sign;

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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		val;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	i = 1;
	while (i < ac)
	{
		val = ft_atoi(av[i]);
		stack_add_back(&a, new_node(val));
		i++;
	}

	t_tracking *track;

	track = malloc(sizeof(t_tracking));
	ft_init_track(&track);
	bubble_sort(&a, &b, ac - 1, &track);
	print_status(&a, &b);
/*	ft_printf("1. État initial (A: 15, 2, 6 | B: vide)\n-->");
	print_status(a, NULL);
	// --- TEST SWAP (sa) ---
	ft_printf("\n2. Action: sa (échanger 15 et 2)\n-->");
	sa(&a);
	print_status(a, b);
	// --- TEST PUSH (pb) ---
	ft_printf("\n3. Action: pb (envoyer 2 vers B)\n-->");
	pb(&a, &b);
	print_status(a, b);
	// --- TEST ROTATE (ra) ---
	// A était [15, 6], devient [6, 15]
	ft_printf("\n4. Action: ra (le premier de A [15] va au fond)\n-->");
	ra(&a);
	print_status(a, b);
	// --- TEST REVERSE ROTATE (rra) ---
	// A était [6, 15], devient [15, 6]
	ft_printf("\n5. Action: rra (le dernier de A [15] revient en haut)\n-->");
	rra(&a);
	print_status(a, b);
	// --- TEST COMBINÉS (ss, rr, rrr) ---
	ft_printf("\n6. Action: pb (pour avoir des éléments dans B)\n-->");
	pb(&a, &b); // A: [6], B: [15, 2]
	print_status(a, b);
	ft_printf("\n7. Action: rrr (reverse rotate A et B)\n-->");
	rrr(&a, &b); // A ne bouge pas (1 seul élem), B: [2, 15]
	print_status(a, b);*/
	return (0);
}

