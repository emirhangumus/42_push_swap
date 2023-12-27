/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:27:27 by egumus            #+#    #+#             */
/*   Updated: 2023/12/16 13:27:56 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_state *state, int print)
{
	t_node	*tmp;

	if (state->size_a < 2)
		return ;
	tmp = state->a;
	state->a = state->a->next;
	tmp->next = state->a->next;
	state->a->next = tmp;
	if (print)
		ft_printf("sa\n");
}

void	sb(t_state *state, int print)
{
	t_node	*tmp;

	if (state->size_b < 2)
		return ;
	tmp = state->b;
	state->b = state->b->next;
	tmp->next = state->b->next;
	state->b->next = tmp;
	if (print)
		ft_printf("sb\n");
}

void	ss(t_state *state)
{
	sa(state, 0);
	sb(state, 0);
	ft_printf("ss\n");
}

void	ra(t_state *state, int print)
{
	t_node	*tmp;

	if (state->size_a < 2)
		return ;
	tmp = state->a;
	state->a = state->a->next;
	tmp->next = NULL;
	add_node(&state->a, tmp);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_state *state, int print)
{
	t_node	*tmp;

	if (state->size_b < 2)
		return ;
	tmp = state->b;
	state->b = state->b->next;
	tmp->next = NULL;
	add_node(&state->b, tmp);
	if (print)
		ft_printf("rb\n");
}
