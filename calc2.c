/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 08:26:32 by egumus            #+#    #+#             */
/*   Updated: 2023/12/16 13:29:32 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_target(t_node *stack_a, t_node *node)
{
	t_node	*tmp;
	t_node	*target;

	tmp = stack_a;
	target = NULL;
	while (tmp)
	{
		if (tmp->nb > node->nb)
		{
			if (target == NULL)
				target = tmp;
			else if (tmp->nb < target->nb)
				target = tmp;
		}
		tmp = tmp->next;
	}
	return (target);
}

void	arr_br(t_state *state, t_node *node)
{
	node->target = find_target(state->a, node);
	if (node->target)
	{
		if (node->target->stack_index != 0)
			node->rra = state->size_a - node->target->stack_index;
		node->rb = node->stack_index;
		node->pa = 1;
		node->cost = total_cost(node);
	}
}

void	ar_brr(t_state *state, t_node *node)
{
	node->target = find_target(state->a, node);
	if (node->target)
	{
		node->ra = node->target->stack_index;
		if (node->stack_index != 0)
			node->rrb = state->size_b - node->stack_index;
		node->pa = 1;
		node->cost = total_cost(node);
	}
}

int	total_cost(t_node *node)
{
	return (node->pa + node->pb + node->sa + node->sb
		+ node->ss + node->ra + node->rb + node->rra
		+ node->rrb + node->rr + node->rrr);
}

void	determine_and_apply_best_cost(t_cost *cost)
{
	if (cost->r_node->cost < cost->rr_node->cost)
	{
		cost->best_cost = 1;
		cost->curr_cost = cost->r_node->cost;
	}
	else
	{
		cost->best_cost = 2;
		cost->curr_cost = cost->rr_node->cost;
	}
	if (cost->arr_br->cost < cost->curr_cost)
	{
		cost->best_cost = 3;
		cost->curr_cost = cost->arr_br->cost;
	}
	if (cost->ar_brr->cost < cost->curr_cost)
	{
		cost->best_cost = 4;
		cost->curr_cost = cost->ar_brr->cost;
	}
	free(cost->r_node);
	free(cost->rr_node);
	free(cost->arr_br);
	free(cost->ar_brr);
}
