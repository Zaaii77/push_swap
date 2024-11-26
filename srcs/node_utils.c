/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:33:57 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/26 15:55:52 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*new_node(int nb)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->next = NULL;
	node->target = NULL;
	node->nb = nb;
	return (node);
}

int	add_node_back(t_stack *a, int nb)
{
	t_node	*node;

	if (!a)
		return (0);
	node = new_node(nb);
	if (!node)
		return (0);
	if (a->bot)
	{
		a->bot->next = node;
		node->prev = a->bot;
	}
	else
		a->top = node;
	a->bot = node;
	a->size++;
	return (1);
}

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	stack->bot = NULL;
	return (stack);
}

int	is_tab_sorted(char **tab)
{
	int	i;
	int	j;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (tab[j] < tab[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
