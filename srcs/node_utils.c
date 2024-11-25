/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:33:57 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/25 01:03:45 by lowatell         ###   ########.fr       */
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

void	fill_stack(t_stack *a, int nb)
{
	t_node	*node;

	if (!a)
		return ;
	node = new_node(nb);
	if (!node)
		return ;//FREE ALL
	if (a->bot)
	{
		a->bot->next = node;
		node->prev = a->bot;
	}
	else
		a->top = node;
	a->bot = node;
	a->size++;
}

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL); //FREE ALL
	stack->size = 0;
	stack->top = NULL;
	stack->bot = NULL;
	return (stack);
}

void	print_stack(t_stack *a)
{
	t_node	*node;

	if (!a)
		return ;
	node = a->top;
	while (node)
	{
		ft_printf("%d\n", node->nb);
		node = node->next;
	}
}

void	print_stack_rev(t_stack *a)
{
	t_node	*node;

	if (!a)
		return ;
	node = a->bot;
	while (node)
	{
		ft_printf("%d\n", node->nb);
		node = node->prev;
	}
}
