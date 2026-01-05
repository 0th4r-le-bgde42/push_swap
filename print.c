/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <ldauber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:04:24 by ldauber           #+#    #+#             */
/*   Updated: 2026/01/05 15:39:46 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_status(t_stack **a, t_stack **b)
{   
    t_stack *tmp;
   
    tmp = *a;
    ft_printf("--- ÉTAT DES PILES ---\n");
    ft_printf("A: ");
    while (tmp)
    {
        ft_printf("[%d]", tmp->value);
        if (tmp->next)
            ft_printf(" -> ");
        tmp = tmp->next;
    }
    ft_printf("\nB: ");
    tmp = *b;
    while (tmp)
    {
        ft_printf("[%d]", tmp->value);
        if (tmp->next)
            ft_printf(" -> ");
        tmp = tmp->next;
    }
    ft_printf("\n----------------------\n");
}

