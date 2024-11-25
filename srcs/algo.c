/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:08:24 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/25 19:57:52 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	three_sort(t_stack *a)
{
	t_node	*max;

	if (!a)
		return ;
	max = max_value(a);
	if (a->top == max)
		ra(a);
	else if (a->top->next == max)
		rra(a);
	if (a->top->nb > a->top->next->nb)
		sa(a);
}

void	push_swap(t_stack *a, t_stack *b, int less_six)
{
	if (a->size > 3 && !is_stack_sorted(a))
		pb(a, b);
	if (a->size > 3 && !is_stack_sorted(a))
		pb(a, b);
	while (a->size > 3 && !is_stack_sorted(a))
	{
		set_index(a, b);
		set_min_closer(a, b);
		set_min_moves(a, b);
		a_to_b(a, b);
	}
	three_sort(a);
	while (b->size > 0)
	{
		set_index(a, b);
		set_max_closer(b, a);
		b_to_a(a, b);
	}
	min_on_top(a, less_six);
}

void	sort(t_stack *a, t_stack *b)
{
	if (!is_stack_sorted(a))
	{
		if (a->size == 2)
			sa(a);
		else if (a->size == 3)
			three_sort(a);
		else if (a->size < 6)
			push_swap(a, b, 1);
		else
			push_swap(a, b, 0);
	}
}

void	a_to_b(t_stack *a, t_stack *b)
{
	t_node	*best;

	if (!a || !b)
		return ;
	best = best_min_move(a);
	if (best->above_median == best->target->above_median)
	{
		if (best->above_median)
		{
			while (a->top != best && b->top != best->target)
				rr(a, b);
		}
		else
		{
			while (a->top != best && b->top != best->target)
				rrr(a, b);
		}
	}
	best_on_top(a, best, 1);
	best_on_top(b, best->target, 0);
	pb(a, b);
}

void	b_to_a(t_stack *a, t_stack *b)
{
	best_on_top(a, b->top->target, 1);
	pa(a, b);
}
