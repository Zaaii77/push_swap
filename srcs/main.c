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
	int		check;

	if (ac < 2)
		return (0);
	check = arg_parsing(ac, av);
	if (check == 0)
		return (print_error(), 2);
	if (check == 2)
		return (0);
	a = stack_init();
	if (!a)
		return (print_error(), 2);
	b = stack_init();
	if (!b)
		return (free_stack(a), print_error(), 2);
	if (fill_stack(ac, av + 1, a))
		sort(a, b);
	else
		return (free_stack(a), free_stack(b), print_error(), 2);
	return (free_stack(a), free_stack(b), 0);
}
