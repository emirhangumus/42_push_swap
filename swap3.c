/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:28:14 by egumus            #+#    #+#             */
/*   Updated: 2023/12/16 13:32:21 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_state *state)
{
	t_node	*tmp;

	if (state->size_a < 1)
		return ;
	tmp = state->a;
	state->a = state->a->next;
	tmp->next = state->b;
	state->b = tmp;
	state->size_a--;
	state->size_b++;
	ft_printf("pb\n");
}

void	reset_stack(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp)
	{
		reinit_node(tmp);
		tmp = tmp->next;
	}
	add_indexes(head);
}

void	reset_both_stacks(t_state *state)
{
	reset_stack(state->a);
	reset_stack(state->b);
}

t_node	*reinit_node(t_node *node)
{
	node->cost = 0;
	node->stack_index = 0;
	node->sa = 0;
	node->sb = 0;
	node->ss = 0;
	node->pa = 0;
	node->pb = 0;
	node->ra = 0;
	node->rb = 0;
	node->rr = 0;
	node->rra = 0;
	node->rrb = 0;
	node->rrr = 0;
	node->target = NULL;
	return (node);
}
