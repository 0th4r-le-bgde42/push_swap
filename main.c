/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 08:25:47 by ldauber           #+#    #+#             */
/*   Updated: 2026/01/05 08:32:19 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

// Utilitaire pour créer un nouveau noeud
t_stack *new_node(int val)
{
    t_stack *node = malloc(sizeof(t_stack));
    if (!node) return (NULL);
    node->value = val;
    node->next = NULL;
    node->prev = NULL;
    return (node);
}

// Fonction d'affichage avancée pour vérifier l'intégrité de la liste
void print_status(t_stack *a, t_stack *b)
{
    ft_printf("\n--- ÉTAT DES PILES ---\n");
    ft_printf("A: ");
    t_stack *tmp = a;
    while (tmp) {
        ft_printf("[%d]", tmp->value);
        if (tmp->next) ft_printf(" -> ");
        tmp = tmp->next;
    }
    ft_printf("\nB: ");
    tmp = b;
    while (tmp) {
        ft_printf("[%d]", tmp->value);
        if (tmp->next) ft_printf(" -> ");
        tmp = tmp->next;
    }
    ft_printf("\n----------------------\n");
}

int main(void)
{
    t_stack *a = NULL;
    t_stack *b = NULL;

    // --- INITIALISATION ---
    // Pile A: 15 -> 2 -> 6
    a = new_node(15);
    a->next = new_node(2); a->next->prev = a;
    a->next->next = new_node(6); a->next->next->prev = a->next;

    ft_printf("1. État initial (A: 15, 2, 6 | B: vide)\n-->");
    print_status(a, b);

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
    print_status(a, b);

    // --- VÉRIFICATION FINALE DES POINTEURS PREV ---
    if (b && b->next && b->next->prev == b)
        ft_printf("\n✅ VÉRIFICATION : Les liens 'prev' sont corrects !\n");
    else
        ft_printf("\n❌ ERREUR : Un lien 'prev' est cassé.\n");

    return (0);
}
