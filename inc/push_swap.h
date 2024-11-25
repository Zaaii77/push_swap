/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:20:47 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/25 19:30:15 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/incs/libft.h"

typedef struct s_node
{
	int				nb;
	int				above_median;
	int				min_moves;
	int				index;
	struct s_node	*target;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
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
void	add_node_back(t_stack *a, int nb);

void	swap(t_stack *s);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	rotate(t_stack *stack);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	rev_rotate(t_stack *stack);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	push(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);

void	min_on_top(t_stack *stack, int less_six);
void	best_on_top(t_stack *stack, t_node *best, int a);
void	a_to_b(t_stack *a, t_stack *b);
void	b_to_a(t_stack *a, t_stack *b);

t_node	*max_value(t_stack *stack);
t_node	*min_value(t_stack *stack);
t_node	*best_min_move(t_stack *stack);
void	set_index(t_stack *a, t_stack *b);
void	set_min_closer(t_stack *a, t_stack *b);
void	set_max_closer(t_stack *b, t_stack *a);
void	set_min_moves(t_stack *a, t_stack *b);
void	set_index_node(t_node *tmp, int i, int med);
int		is_stack_sorted(t_stack *a);

void	three_sort(t_stack *a);
void	sort(t_stack *a, t_stack *b);
void	push_swap(t_stack *a, t_stack *b, int less_six);

int		is_integer(char *s);
int		is_dup(char **av);
int		is_int_max(char *s);
int		check_tab(char **av);
int		arg_parsing(int ac, char **av);

#endif
