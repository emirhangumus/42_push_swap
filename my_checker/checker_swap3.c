/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_swap3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:28:14 by egumus            #+#    #+#             */
/*   Updated: 2023/12/17 18:20:35 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}

void	apply_moves(t_state *state)
{
	t_node	*tmp;

	tmp = state->moves;
	while (tmp)
	{
		apply_move(state, tmp);
		tmp = tmp->next;
	}
}
