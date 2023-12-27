/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:06:14 by egumus            #+#    #+#             */
/*   Updated: 2023/12/17 18:21:31 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_get_move2(char *line, int len)
{
	if (len == 4 && line[0] == 'r' && line[1] == 'r' && line[2] == 'a' && \
			line[3] == '\n')
		return (RRA);
	else if (len == 4 && line[0] == 'r' && line[1] == 'r' && line[2] == 'b' && \
			line[3] == '\n')
		return (RRB);
	else if (len == 4 && line[0] == 'r' && line[1] == 'r' && line[2] == 'r' && \
			line[3] == '\n')
		return (RRR);
	else
		return (-1);
}

int	ft_get_move(char *line, int len)
{
	if (len == 3 && line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		return (SA);
	else if (len == 3 && line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		return (SB);
	else if (len == 3 && line[0] == 's' && line[1] == 's' && line[2] == '\n')
		return (SS);
	else if (len == 3 && line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		return (PA);
	else if (len == 3 && line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		return (PB);
	else if (len == 3 && line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		return (RA);
	else if (len == 3 && line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		return (RB);
	else if (len == 3 && line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		return (RR);
	else
		return (ft_get_move2(line, len));
}

void	add_new_node_to_a(t_state *state, char *str)
{
	int	nb;

	nb = ft_atoi(str);
	if (is_existing(state->a, nb))
		ft_checker_error(state);
	add_node(&state->a, new_node(nb));
	state->size_a++;
}

void	fill_stack_a(t_state *state, int argc, char **argv)
{
	char	**split;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split || !split[0])
		{
			free_split(split);
			ft_checker_error(state);
		}
		j = 0;
		while (split[j])
		{
			add_new_node_to_a(state, split[j]);
			j++;
		}
		i++;
		free_split(split);
	}
}

void	apply_move(t_state *state, t_node *s)
{
	if (s->nb == SA)
		sa(state);
	else if (s->nb == SB)
		sb(state);
	else if (s->nb == SS)
		ss(state);
	else if (s->nb == PA)
		pa(state);
	else if (s->nb == PB)
		pb(state);
	else if (s->nb == RA)
		ra(state);
	else if (s->nb == RB)
		rb(state);
	else if (s->nb == RR)
		rr(state);
	else if (s->nb == RRA)
		rra(state);
	else if (s->nb == RRB)
		rrb(state);
	else if (s->nb == RRR)
		rrr(state);
}
