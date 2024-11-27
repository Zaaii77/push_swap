/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:33:30 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/27 19:16:17 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	(void)ac;
	if (!arg_parsing(av))
		return (print_error(), 2);
	a = stack_init();
	if (!a)
		return (print_error(), 2);
	b = stack_init();
	if (!b)
		return (free_stack(a), print_error(), 2);
	if (fill_stack(av + 1, a))
		sort(a, b);
	else
		return (free_stack(a), free_stack(b), print_error(), 2);
	return (free_stack(a), free_stack(b), 0);
}
