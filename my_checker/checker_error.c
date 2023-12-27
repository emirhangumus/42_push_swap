/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:21:38 by egumus            #+#    #+#             */
/*   Updated: 2023/12/17 18:28:59 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_list(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	free_checker_state(t_state *state)
{
	if (state->a)
		free_list(state->a);
	if (state->b)
		free_list(state->b);
	if (state->moves)
		free_list(state->moves);
	free(state);
}

void	ft_checker_error(t_state *state)
{
	if (state)
		free_checker_state(state);
	ft_printf("Error\n");
	exit(1);
}
