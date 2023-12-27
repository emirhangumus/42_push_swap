/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:25:11 by egumus            #+#    #+#             */
/*   Updated: 2023/12/17 03:44:28 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int				nb;
	int				index;
	int				stack_index;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
	int				cost;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}	t_node;

typedef struct s_state
{
	t_node	*a;
	t_node	*b;
	t_node	*c;
	int		general_size;
	int		size_a;
	int		size_b;
}	t_state;

typedef struct s_cost
{
	t_node	*node;
	t_node	*r_node;
	t_node	*rr_node;
	t_node	*arr_br;
	t_node	*ar_brr;
	int		best_cost;
	int		curr_cost;
	int		prev_cost;
}	t_cost;

t_node	*new_node(int nb);
void	add_node(t_node **head, t_node *node);
t_node	*copy_list(t_node *head);
int		stack_size(t_node *head);
t_node	*reinit_node(t_node *node);
t_node	*node_copy(t_node *node);

void	ft_error_clear(t_state *state);

void	check_args(int argc, char **argv);
void	fill_stack_a(t_state *state, int argc, char **argv);

void	free_state(t_state *state);
void	free_list(t_node *head);
void	free_split(char **split);

int		ft_atoi_extended(const char *nptr);

void	bubble_sort(t_node **head);

void	sort_it(t_state *state);
void	big_sort(t_state *state);
void	sort_three(t_state *state);
int		is_sorted(t_node *head);
void	push_everything_to_b_except_three(t_state *state);
void	add_indexes(t_node *head);
t_node	*is_bigger_than_all(t_node *three_number, int nb);
t_node	*get_biggest_three(t_node *head);
t_node	*get_lowest_cost(t_node *head);
void	sort_five(t_state *state);
void	add_sorted_indexes(t_state *state);

void	both_rr(t_state *state, t_node *node);
void	both_r(t_state *state, t_node *node);
void	calculate_rr(t_node *node);
void	calculate_r(t_node *node);
void	calculate_cost(t_state *state);
void	calc_target_cost(t_state *state, t_node *node, t_cost *cost);
void	determine_and_apply_best_cost(t_cost *cost);
void	arr_br(t_state *state, t_node *node);
void	ar_brr(t_state *state, t_node *node);
void	apply_sort(t_state *state, t_node *lowest_cost);
t_node	*find_target(t_node *head, t_node *node);
int		total_cost(t_node *node);
void	reset_stack(t_node *head);
void	reset_both_stacks(t_state *state);

void	sa(t_state *state, int print);
void	sb(t_state *state, int print);
void	ss(t_state *state);
void	ra(t_state *state, int print);
void	rb(t_state *state, int print);
void	rr(t_state *state);
void	rra(t_state *state, int print);
void	rrb(t_state *state, int print);
void	rrr(t_state *state);
void	pa(t_state *state);
void	pb(t_state *state);

#endif