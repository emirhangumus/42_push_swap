/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:19:16 by egumus            #+#    #+#             */
/*   Updated: 2023/12/17 18:30:26 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_state(t_state *state)
{
	state->a = NULL;
	state->b = NULL;
	state->c = NULL;
	state->general_size = 0;
	state->size_a = 0;
	state->size_b = 0;
}

int	main(int argc, char **argv)
{
	t_state	*state;

	if (argc < 2)
		return (0);
	state = malloc(sizeof(t_state));
	if (!state)
		return (0);
	init_state(state);
	check_args(argc, argv);
	fill_stack_a(state, argc, argv);
	state->c = copy_list(state->a);
	state->size_a = stack_size(state->a);
	state->general_size = state->size_a;
	add_indexes(state->a);
	sort_it(state);
	free_state(state);
	return (0);
}
