/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:30:09 by egumus            #+#    #+#             */
/*   Updated: 2023/12/17 03:57:16 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_print_list(t_node *lst)
{
	t_node	*tmp;

	tmp = lst;
	while (tmp)
	{
		ft_printf("%d\n", tmp->nb);
		tmp = tmp->next;
	}
}

t_node	*new_node(int nb)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->nb = nb;
	node->next = NULL;
	node->prev = NULL;
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
