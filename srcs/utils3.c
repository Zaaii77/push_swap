/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:28:03 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/27 19:08:26 by lowatell         ###   ########.fr       */
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

int	fill_stack(char **av, t_stack *a)
{
	if (!av || !a)
		return (0);
	if (!add_all(av, a))
		return (0);
	return (1);
}

int	add_all(char **av, t_stack *a)
{
	int		i;
	int		j;
	char	**tab;

	if (!av || !a)
		return (0);
	i = 0;
	while (av[i])
	{
		j = 0;
		tab = ft_split(av[i], ' ');
		if (!tab)
			return (0);
		while (tab[j])
		{
			if (!add_node_back(a, ft_atoi(tab[j])))
				return (free_tab(tab), 0);
			j++;
		}
		free_tab(tab);
		i++;
	}
	if (!is_stack_dup(a))
		return (0);
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
	write(2, "Error\n", 6);
}
