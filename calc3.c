/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 08:28:13 by egumus            #+#    #+#             */
/*   Updated: 2023/12/16 08:31:54 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_cost(t_state *state)
{
	t_node	*tmp;
	t_cost	*cost;

	cost = malloc(sizeof(t_cost));
	if (!cost)
		ft_error_clear(state);
	tmp = state->b;
	cost->curr_cost = 0;
	cost->prev_cost = 0;
	cost->best_cost = 0;
	while (tmp)
	{
		calc_target_cost(state, tmp, cost);
		tmp = tmp->next;
	}
	free(cost);
}

t_node	*get_lowest_cost(t_node *head)
{
	t_node	*tmp;
	t_node	*lowest;

	tmp = head;
	lowest = tmp;
	while (tmp)
	{
		if (tmp->cost < lowest->cost)
			lowest = tmp;
		tmp = tmp->next;
	}
	return (lowest);
}

void	apply_sort_2(t_state *state, t_node *lowest_cost)
{
	int		i;

	i = -1;
	while (++i < lowest_cost->rb)
		rb(state, 1);
	i = -1;
	while (++i < lowest_cost->rra)
		rra(state, 1);
	i = -1;
	while (++i < lowest_cost->rrb)
		rrb(state, 1);
	i = -1;
	while (++i < lowest_cost->rr)
		rr(state);
	i = -1;
	while (++i < lowest_cost->rrr)
		rrr(state);
}

void	apply_sort(t_state *state, t_node *lowest_cost)
{
	int		i;

	i = -1;
	while (++i < lowest_cost->sa)
		sa(state, 1);
	i = -1;
	while (++i < lowest_cost->sb)
		sb(state, 1);
	i = -1;
	while (++i < lowest_cost->ss)
		ss(state);
	i = -1;
	while (++i < lowest_cost->ra)
		ra(state, 1);
	apply_sort_2(state, lowest_cost);
	pa(state);
}
