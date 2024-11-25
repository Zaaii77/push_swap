/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:19:55 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/25 14:28:48 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rev_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	last = stack->bot;
	first->prev = last;
	last->next = first;
	stack->bot = last->prev;
	stack->bot->next = NULL;
	last->prev = NULL;
	stack->top = last;
}

void	rra(t_stack *a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}
