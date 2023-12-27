/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 08:22:00 by egumus            #+#    #+#             */
/*   Updated: 2023/12/16 13:29:19 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_it(t_state *state)
{
	bubble_sort(&state->c);
	if (is_sorted(state->a))
		return ;
	if (state->size_a <= 3)
		sort_three(state);
	else if (state->size_a <= 5)
		sort_five(state);
	else
	{
		add_sorted_indexes(state);
		big_sort(state);
	}
}
