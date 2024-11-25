/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:28:03 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/25 20:39:04 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	best_on_top(t_stack *stack, t_node *best, int a)
{
	if (!best)
		return ;
	while (stack->top != best)
	{
		if (a)
		{
			if (best->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else
		{
			if (best->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

int	fill_stack(int ac, char **av, t_stack *a)
{
	char	**tab;

	if (!av || !a)
		return (0);
	if (ac == 2)
	{
		tab = ft_split(av[0], ' ');
		if (!tab)
			return (0);
		if (!add_all(tab, a))
			return (free_tab(tab), 0);
		free_tab(tab);
	}
	else
		if (!add_all(av, a))
			return (0);
	return (1);
}

int	add_all(char **av, t_stack *a)
{
	int	i;

	if (!av || !a)
		return (0);
	i = 0;
	while (av[i])
	{
		if (!add_node_back(a, ft_atoi(av[i])))
			return (0);
		i++;
	}
	return (1);
}

void	free_stack(t_stack *a)
{
	t_node	*node;
	t_node	*tmp;

	if (!a)
		return ;
	tmp = NULL;
	node = NULL;
	if (a->top)
		node = a->top;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
		tmp = NULL;
	}
	a->top = NULL;
	a->top = NULL;
	free(a);
}

void	print_error(void)
{
	ft_printf("Error\n");
}
