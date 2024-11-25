/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:20:47 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/25 01:04:01 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/incs/libft.h"

typedef struct	s_node
{
	int		nb;
	int		above_median;
	int		min_moves;
	int		index;
	struct s_node	*target;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct	s_stack
{
	t_node	*top;
	t_node	*bot;
	int		size;
}	t_stack;

//A DELETE
void	print_stack(t_stack *a);
void	print_stack_rev(t_stack *a);

t_node	*new_node(int nb);
t_stack	*stack_init(void);
void	fill_stack(t_stack *a, int nb);

void	swap(t_stack *s);
void	sa(t_stack *a);
void	sb(t_stack *b);

#endif
