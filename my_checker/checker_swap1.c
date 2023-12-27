/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_swap1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:27:27 by egumus            #+#    #+#             */
/*   Updated: 2023/12/17 17:29:29 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_state *state)
{
	t_node	*tmp;

	if (state->size_a < 2)
		return ;
	tmp = state->a;
	state->a = state->a->next;
	tmp->next = state->a->next;
	state->a->next = tmp;
}

void	sb(t_state *state)
{
	t_node	*tmp;

	if (state->size_b < 2)
		return ;
	tmp = state->b;
	state->b = state->b->next;
	tmp->next = state->b->next;
	state->b->next = tmp;
}

void	ss(t_state *state)
{
	sa(state);
	sb(state);
}

void	ra(t_state *state)
{
	t_node	*tmp;

	if (state->size_a < 2)
		return ;
	tmp = state->a;
	state->a = state->a->next;
	tmp->next = NULL;
	add_node(&state->a, tmp);
}

void	rb(t_state *state)
{
	t_node	*tmp;

	if (state->size_b < 2)
		return ;
	tmp = state->b;
	state->b = state->b->next;
	tmp->next = NULL;
	add_node(&state->b, tmp);
}
