/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:02:05 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/25 17:49:58 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	set_index(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	int		med_a;
	int		med_b;
	int		i;

	i = 0;
	tmp = a->top;
	med_a = a->size / 2;
	med_b = b->size / 2;
	set_index_node(tmp, i, med_a);
	i = 0;
	tmp = b->top;
	set_index_node(tmp, i, med_b);
}

t_node	*min_value(t_stack *stack)
{
	t_node	*min;
	t_node	*tmp;

	if (!stack)
		return (NULL);
	tmp = stack->top;
	min = tmp;
	while (tmp)
	{
		if (tmp->nb < min->nb)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_node	*max_value(t_stack *stack)
{
	t_node	*max;
	t_node	*tmp;

	if (!stack)
		return (NULL);
	tmp = stack->top;
	max = tmp;
	while (tmp)
	{
		if (tmp->nb > max->nb)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

void	set_index_node(t_node *tmp, int i, int med)
{
	while (tmp)
	{
		if (i < med)
			tmp->above_median = 1;
		else
			tmp->above_median = 0;
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
}

void	min_on_top(t_stack *stack, int less_six)
{
	t_node	*min;

	if (!stack)
		return ;
	min = min_value(stack);
	if (!min)
		return ;
	while (stack->top != min)
	{
		if (less_six)
		{
			if (min->above_median)
				rra(stack);
			else
				ra(stack);
		}
		else
		{
			if (min->above_median)
				ra(stack);
			else
				rra(stack);
		}
	}
}
