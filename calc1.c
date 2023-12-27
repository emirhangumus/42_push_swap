/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 08:24:36 by egumus            #+#    #+#             */
/*   Updated: 2023/12/16 08:25:41 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_r(t_node *node)
{
	int		ra;
	int		rb;

	ra = node->ra;
	rb = node->rb;
	if (ra > rb)
	{
		node->rb = 0;
		node->ra = ra - rb;
		node->rr = rb;
	}
	else if (ra < rb)
	{
		node->ra = 0;
		node->rb = rb - ra;
		node->rr = ra;
	}
	else if (ra == rb)
	{
		node->ra = 0;
		node->rb = 0;
		node->rr = ra;
	}
}

void	calculate_rr(t_node *node)
{
	int		rra;
	int		rrb;

	rra = node->rra;
	rrb = node->rrb;
	if (rra > rrb)
	{
		node->rrb = 0;
		node->rra = rra - rrb;
		node->rrr = rrb;
	}
	else if (rra < rrb)
	{
		node->rra = 0;
		node->rrb = rrb - rra;
		node->rrr = rra;
	}
	else if (rra == rrb)
	{
		node->rra = 0;
		node->rrb = 0;
		node->rrr = rra;
	}
}

void	both_r(t_state *state, t_node *node)
{
	node->target = find_target(state->a, node);
	if (node->target)
	{
		node->ra = node->target->stack_index;
		node->rb = node->stack_index;
		calculate_r(node);
		node->pa = 1;
		node->cost = total_cost(node);
	}
}

void	both_rr(t_state *state, t_node *node)
{
	node->target = find_target(state->a, node);
	if (node->target)
	{
		if (node->target->stack_index != 0)
			node->rra = state->size_a - node->target->stack_index;
		if (node->stack_index != 0)
			node->rrb = state->size_b - node->stack_index;
		calculate_rr(node);
		node->pa = 1;
		node->cost = total_cost(node);
	}
}
