#include "push_swap.h"

// SUPP
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
