/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:24:27 by egumus            #+#    #+#             */
/*   Updated: 2023/12/16 13:32:13 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_min(t_node *head)
{
	t_node	*min;

	min = head;
	while (head)
	{
		if (head->nb < min->nb)
			min = head;
		head = head->next;
	}
	return (min);
}

t_node	*get_max(t_node *head)
{
	t_node	*max;

	max = head;
	while (head)
	{
		if (head->nb > max->nb)
			max = head;
		head = head->next;
	}
	return (max);
}

void	add_sorted_indexes(t_state *state)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = state->c;
	while (tmp)
	{
		tmp2 = state->a;
		while (tmp2)
		{
			if (tmp->nb == tmp2->nb)
			{
				tmp2->index = tmp->index;
				break ;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	sort_three(t_state *state)
{
	t_node	*min;
	t_node	*max;

	min = get_min(state->a);
	max = get_max(state->a);
	if (min->stack_index == 1 && max->stack_index == 2)
		sa(state, 1);
	else if (min->stack_index == 0 && max->stack_index == 1)
	{
		sa(state, 1);
		ra(state, 1);
	}
	else if (min->stack_index == 2 && max->stack_index == 1)
		rra(state, 1);
	else if (min->stack_index == 1 && max->stack_index == 0)
		ra(state, 1);
	else if (min->stack_index == 2 && max->stack_index == 0)
	{
		ra(state, 1);
		sa(state, 1);
	}
}

void	sort_five(t_state *state)
{
	add_sorted_indexes(state);
	push_everything_to_b_except_three(state);
	add_indexes(state->a);
	sort_three(state);
	if (state->b->next != NULL && state->b->nb < state->b->next->nb)
		sb(state, 1);
	pa(state);
	if (state->general_size == 5)
		pa(state);
}
