/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:33:30 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/25 20:38:36 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (!arg_parsing(ac, av))
		return (print_error(), 2);
	a = stack_init();
	if (!a)
		return (2);
	b = stack_init();
	if (!b)
		return (free_stack(a), 2);
	if (fill_stack(ac, av + 1, a))
		sort(a, b);
	else
		print_error();
	free_stack(a);
	free_stack(b);
	return (0);
}
