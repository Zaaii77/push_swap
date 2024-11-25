/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:33:30 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/25 14:58:40 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		data;

	a = stack_init();
	b = stack_init();
	i = 1;
	while (i < ac)
	{
		data = ft_atoi(av[i]);
		fill_stack(b, data);
		i++;
	}
	ft_printf("stack b\n");
	print_stack(b);
	pb(a, b);
	pa(a, b);
	ft_printf("stack a\n");
	print_stack(a);
	ft_printf("stack b\n");
	print_stack(b);
}
