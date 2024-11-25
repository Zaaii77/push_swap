/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:25:04 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/25 17:40:01 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	set_min_closer(t_stack *a, t_stack *b)
{
	t_node	*a_tmp;
	t_node	*b_tmp;
	int		min;

	if (!a || !b)
		return ;
	a_tmp = a->top;
	while (a_tmp)
	{
		min = INT_MIN;
		b_tmp = b->top;
		a_tmp->target = max_value(b);
		while (b_tmp)
		{
			if (a_tmp->nb > b_tmp->nb && b_tmp->nb >= min)
			{
				a_tmp->target = b_tmp;
				min = b_tmp->nb;
			}
			b_tmp = b_tmp->next;
		}
		a_tmp = a_tmp->next;
	}
}

void	set_max_closer(t_stack *b, t_stack *a)
{
	int		max;
	t_node	*a_tmp;
	t_node	*b_tmp;

	if (!b || !a)
		return ;
	b_tmp = b->top;
	while (b_tmp)
	{
		max = INT_MAX;
		b_tmp->target = min_value(a);
		a_tmp = a->top;
		while (a_tmp)
		{
			if (b_tmp->nb < a_tmp->nb && a_tmp->nb <= max)
			{
				max = a_tmp->nb;
				b_tmp->target = a_tmp;
			}
			a_tmp = a_tmp->next;
		}
		b_tmp = b_tmp->next;
	}
}

int	is_stack_sorted(t_stack *a)
{
	t_node	*tmp;

	if (!a || a->size < 2)
		return (1);
	tmp = a->top;
	while (tmp->next)
	{
		if (tmp->next->nb < tmp->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	set_min_moves(t_stack *a, t_stack *b)
{
	int		a_moves;
	int		b_moves;
	t_node	*tmp;

	if (!a || !b)
		return ;
	tmp = a->top;
	a_moves = 0;
	b_moves = 0;
	while (tmp)
	{
		if (tmp->index <= a->size / 2)
			a_moves = tmp->index;
		else
			a_moves = a->size - tmp->index;
		if (tmp->target->index <= b->size / 2)
			b_moves = tmp->target->index;
		else
			b_moves = b->size - tmp->target->index;
		tmp->min_moves = a_moves + b_moves;
		tmp = tmp->next;
	}
}

t_node	*best_min_move(t_stack *stack)
{
	int		min_moves;
	t_node	*best;
	t_node	*tmp;

	if (!stack)
		return (NULL);
	min_moves = INT_MAX;
	best = stack->top;
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->min_moves < min_moves)
		{
			min_moves = tmp->min_moves;
			best = tmp;
		}
		tmp = tmp->next;
	}
	return (best);
}
