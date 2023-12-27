/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:27:45 by egumus            #+#    #+#             */
/*   Updated: 2023/12/16 13:32:17 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_state *state)
{
	ra(state, 0);
	rb(state, 0);
	ft_printf("rr\n");
}

void	rra(t_state *state, int print)
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
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_state *state, int print)
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
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_state *state)
{
	rra(state, 0);
	rrb(state, 0);
	ft_printf("rrr\n");
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
	ft_printf("pa\n");
}
