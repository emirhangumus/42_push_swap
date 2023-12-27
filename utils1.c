/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 08:34:01 by egumus            #+#    #+#             */
/*   Updated: 2023/12/16 13:33:00 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_indexes(t_node *head)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = head;
	while (tmp)
	{
		tmp->stack_index = i;
		i++;
		tmp = tmp->next;
	}
}

void	bubble_sort(t_node **head)
{
	t_node	*tmp;
	t_node	*tmp2;
	int		nb;

	tmp = *head;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->nb > tmp2->nb)
			{
				nb = tmp->nb;
				tmp->nb = tmp2->nb;
				tmp2->nb = nb;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	add_indexes(*head);
}
