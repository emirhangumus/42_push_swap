/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 08:37:01 by egumus            #+#    #+#             */
/*   Updated: 2023/12/16 13:31:04 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int nb)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->nb = nb;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	reinit_node(node);
	return (node);
}

void	add_node(t_node **head, t_node *node)
{
	t_node	*tmp;

	if (!*head)
	{
		*head = node;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->prev = tmp;
}

t_node	*copy_list(t_node *head)
{
	t_node	*new;
	t_node	*tmp;

	new = NULL;
	tmp = head;
	while (tmp)
	{
		add_node(&new, new_node(tmp->nb));
		tmp = tmp->next;
	}
	return (new);
}

int	stack_size(t_node *head)
{
	int		size;
	t_node	*tmp;

	size = 0;
	tmp = head;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

t_node	*node_copy(t_node *node)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->nb = node->nb;
	new->index = node->index;
	new->stack_index = node->stack_index;
	new->next = NULL;
	new->prev = NULL;
	new->cost = node->cost;
	new->sa = node->sa;
	new->sb = node->sb;
	new->ss = node->ss;
	new->pa = node->pa;
	new->pb = node->pb;
	new->ra = node->ra;
	new->rb = node->rb;
	new->rr = node->rr;
	new->rra = node->rra;
	new->rrb = node->rrb;
	new->rrr = node->rrr;
	new->target = node->target;
	return (new);
}
