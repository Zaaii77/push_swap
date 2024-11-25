/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:08:15 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/25 20:09:14 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_dup(char **av)
{
	int	i;
	int	j;

	if (!av)
		return (0);
	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atol(av[j]) == ft_atol(av[i]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_integer(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_int_max(char *s)
{
	ssize_t	nbr;

	if (!s)
		return (0);
	nbr = ft_atol(s);
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (1);
	return (0);
}

int	check_tab(char **av)
{
	int	i;

	if (!av)
		return (0);
	i = 0;
	if (!is_dup(av))
		return (0);
	while (av[i])
	{
		if (is_int_max(av[i]) || !is_integer(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	arg_parsing(int ac, char **av)
{
	char	**tab;

	if (!av)
		return (0);
	else if (!av[1][0])
		return (0);
	else if (ac < 2)
		return (0);
	else if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		if (!tab || !check_tab(tab))
			return (free_tab(tab), 0);
	}
	else
		if (!check_tab(av + 1))
			return (0);
	return (1);
}
