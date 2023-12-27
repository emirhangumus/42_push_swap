/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_swap2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:27:45 by egumus            #+#    #+#             */
/*   Updated: 2023/12/17 17:29:32 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rr(t_state *state)
{
	ra(state);
	rb(state);
}

void	rra(t_state *state)
{
	t_node	*tmp;

	if (state->size_a < 2)
		return ;
	tmp = state->a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = state->a;
	state->a = tmp->next;
	tmp->next = NULL;
}

void	rrb(t_state *state)
{
	t_node	*tmp;

	if (state->size_b < 2)
		return ;
	tmp = state->b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = state->b;
	state->b = tmp->next;
	tmp->next = NULL;
}

void	rrr(t_state *state)
{
	rra(state);
	rrb(state);
}

void	pa(t_state *state)
{
	t_node	*tmp;

	if (state->size_b < 1)
		return ;
	tmp = state->b;
	state->b = state->b->next;
	tmp->next = state->a;
	state->a = tmp;
	state->size_a++;
	state->size_b--;
}
