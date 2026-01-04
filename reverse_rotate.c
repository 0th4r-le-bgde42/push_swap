/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:20:33 by ldauber           #+#    #+#             */
/*   Updated: 2025/12/30 15:21:07 by ldauber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	first = *stack;
	while (last->next != NULL)
		last = last->next;
	if (last->prev)
		last->prev->next = NULL;
	last->next = first;
	first->prev = last;
	last->prev = NULL;
	*stack = last;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}

/*#include <stdio.h>
#include <stdlib.h>

// Utilitaire pour créer un noeud
t_stack *new_node(int val)
{
    t_stack *node = malloc(sizeof(t_stack));
    if (!node) return (NULL);
    node->value = val;
    node->next = NULL;
    node->prev = NULL;
    return (node);
}

// Affichage détaillé pour vérifier les liens doublement chaînés
void print_debug(char *name, t_stack *s)
{
    printf("Pile %s: ", name);
    if (!s) printf("(vide)");
    while (s)
    {
        printf("[%d", s->value);
        if (s->prev == NULL) printf("*"); // Indique le sommet
        printf("] ");
        s = s->next;
    }
    printf("\n");
}

int main(void)
{
    t_stack *a = NULL;
    t_stack *b = NULL;

    // Remplissage Pile A : 1 -> 2 -> 3
    a = new_node(1);
    a->next = new_node(2); a->next->prev = a;
    a->next->next = new_node(3); a->next->next->prev = a->next;

    // Remplissage Pile B : 10 -> 20 -> 30
    b = new_node(10);
    b->next = new_node(20); b->next->prev = b;
    b->next->next = new_node(30); b->next->next->prev = b->next;

    printf("--- ÉTAT INITIAL ---\n");
    print_debug("A", a);
    print_debug("B", b);

    printf("\nExécution de rrr (Double Reverse Rotate)...\n");
    rrr(&a, &b);

    printf("\n--- APRÈS RRR ---\n");
    print_debug("A", a); // Doit afficher : [3*] [1] [2]
    print_debug("B", b); // Doit afficher : [30*] [10] [20]

    // Vérification de sécurité
    if (a && a->value == 3 && a->prev == NULL && b && b->value == 30)
        printf("\n✅ Succès : Les deux piles ont pivoté et les 
					sommets sont corrects.\n");
    else
        printf("\n❌ Erreur : Problème de pointeurs après rrr.\n");

    return (0);
}*/
