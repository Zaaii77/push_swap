/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:33:05 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/25 14:59:47 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push(t_stack *a, t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (!a || a->size < 1 || !b)
		return ;
	first = a->top;
	second = a->top->next;
	if (b->top)
	{
		b->top->prev = first;
		first->prev = NULL;
	}
	if (!b->bot)
		b->bot = first;
	first->next = b->top;
	if (second)
		second->prev = NULL;
	b->top = first;
	a->top = second;
	a->size--;
	b->size++;
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_printf("pb\n");
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_printf("pa\n");
}
