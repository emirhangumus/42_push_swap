/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 08:27:07 by egumus            #+#    #+#             */
/*   Updated: 2023/12/16 14:14:13 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_target_cost(t_state *state, t_node *node, t_cost *cost)
{
	both_r(state, node);
	cost->r_node = node_copy(node);
	reinit_node(node);
	add_indexes(state->b);
	both_rr(state, node);
	cost->rr_node = node_copy(node);
	reinit_node(node);
	add_indexes(state->b);
	arr_br(state, node);
	cost->arr_br = node_copy(node);
	reinit_node(node);
	add_indexes(state->b);
	ar_brr(state, node);
	cost->ar_brr = node_copy(node);
	reinit_node(node);
	add_indexes(state->b);
	determine_and_apply_best_cost(cost);
	if (cost->best_cost == 1)
		both_r(state, node);
	else if (cost->best_cost == 2)
		both_rr(state, node);
	else if (cost->best_cost == 3)
		arr_br(state, node);
	else if (cost->best_cost == 4)
		ar_brr(state, node);
}

t_node	*find_min_number(t_node *head)
{
	t_node	*tmp;
	t_node	*min;

	tmp = head;
	min = tmp;
	while (tmp)
	{
		if (tmp->nb < min->nb)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void	actual_sort(t_state *state)
{
	t_node	*lowest_cost;
	t_node	*min_number;

	while (state->size_b > 0)
	{
		calculate_cost(state);
		lowest_cost = get_lowest_cost(state->b);
		apply_sort(state, lowest_cost);
		reset_both_stacks(state);
	}
	min_number = find_min_number(state->a);
	if (min_number->stack_index > state->size_a / 2)
	{
		while (state->a->nb != min_number->nb)
			rra(state, 1);
	}
	else
	{
		while (state->a->nb != min_number->nb)
			ra(state, 1);
	}
}

void	big_sort(t_state *state)
{
	push_everything_to_b_except_three(state);
	reset_stack(state->a);
	reset_stack(state->b);
	sort_three(state);
	add_indexes(state->a);
	actual_sort(state);
}
