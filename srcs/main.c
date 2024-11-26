/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:33:30 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/26 12:21:52 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	if (!arg_parsing(ac, av))
		return (print_error(), 2);
	a = stack_init();
	if (!a)
		return (print_error(), 2);
	b = stack_init();
	if (!b)
		return (free_stack(a), print_error(), 2);
	if (fill_stack(ac, av + 1, a))
		sort(a, b);
	else
	{
		free_stack(a);
		free_stack(b);
		return (print_error(), 2);
	}
	free_stack(a);
	free_stack(b);
	return (0);
}
