/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 08:22:46 by egumus            #+#    #+#             */
/*   Updated: 2023/12/16 08:23:08 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*is_bigger_than_all(t_node *three_number, int nb)
{
	t_node	*number_1;
	t_node	*number_2;
	t_node	*number_3;
	t_node	*tmp;
	t_node	*lowest;

	number_1 = three_number;
	number_2 = three_number->next;
	number_3 = three_number->next->next;
	tmp = three_number;
	lowest = number_1;
	while (tmp)
	{
		if (tmp->nb < lowest->nb)
			lowest = tmp;
		tmp = tmp->next;
	}
	if (nb < lowest->nb)
		return (NULL);
	return (lowest);
}

t_node	*get_biggest_three(t_node *head)
{
	t_node	*biggest_three;
	t_node	*tmp;
	t_node	*lowest;
	int		i;

	biggest_three = NULL;
	tmp = head;
	i = 0;
	while (i < 3)
	{
		add_node(&biggest_three, new_node(tmp->nb));
		tmp = tmp->next;
		i++;
	}
	while (tmp)
	{
		lowest = is_bigger_than_all(biggest_three, tmp->nb);
		if (lowest)
		{
			lowest->nb = tmp->nb;
			lowest->index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (biggest_three);
}

void	push_everything_to_b_except_three(t_state *state)
{
	t_node	*biggest_three;
	t_node	*tmp;
	t_node	*next;

	biggest_three = get_biggest_three(state->a);
	tmp = state->a;
	next = state->a;
	while (state->size_a > 3)
	{
		next = tmp->next;
		if (tmp->nb != biggest_three->nb && tmp->nb != biggest_three->next->nb
			&& tmp->nb != biggest_three->next->next->nb)
			pb(state);
		else
			ra(state, 1);
		tmp = next;
	}
	free_list(biggest_three);
}
