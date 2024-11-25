/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:33:30 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/25 01:04:14 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
//	t_node	*tmp;
//	t_stack	*b;
	int		i;
	int		data;

	a = stack_init();
//	b = stack_init();
	i = 1;
	while (i < ac)
	{
		data = ft_atoi(av[i]);
		fill_stack(a, data);
		i++;
	}
	print_stack_rev(a);
	sa(a);
	print_stack_rev(a);
}
