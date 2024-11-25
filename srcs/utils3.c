/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:28:03 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/25 17:18:15 by lowatell         ###   ########.fr       */
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
