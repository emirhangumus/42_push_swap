/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:27:11 by egumus            #+#    #+#             */
/*   Updated: 2023/12/17 18:29:35 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_state(t_state *state)
{
	state->a = NULL;
	state->b = NULL;
	state->moves = NULL;
	state->size_a = 0;
	state->size_b = 0;
}

void	init_moves(t_state *state)
{
	char	*line;
	int		move;

	line = "";
	while (line != NULL)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		move = ft_get_move(line, (int)ft_strlen(line));
		if (move == -1)
			ft_checker_error(state);
		add_node(&state->moves, new_node(move));
		free(line);
	}
}

void	ft_logic(t_state *state)
{
	if (state->size_a == 1)
	{
		ft_printf("OK\n");
		return ;
	}
	init_moves(state);
	apply_moves(state);
	if (is_sorted(state->a) && state->size_b == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_state	*state;

	if (ac < 2)
		return (0);
	check_args(ac, av);
	state = malloc(sizeof(t_state));
	if (!state)
		return (1);
	init_state(state);
	fill_stack_a(state, ac, av);
	ft_logic(state);
	free_checker_state(state);
	return (0);
}
