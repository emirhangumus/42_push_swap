/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:03:53 by egumus            #+#    #+#             */
/*   Updated: 2023/12/17 19:00:24 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_existing(t_node *head, int nb)
{
	t_node	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->nb == nb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	add_new_node_to_a(t_state *state, char *str)
{
	int	nb;

	nb = ft_atoi(str);
	if (is_existing(state->a, nb))
		ft_error_clear(state);
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
			ft_error_clear(state);
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

void	checker_split_helper(char *str)
{
	int		k;
	char	*actual;

	k = 0;
	while (str[k])
	{
		if (k == 0 && (str[k] == '+' || str[k] == '-'))
			k++;
		if (!ft_isdigit(str[k]))
			ft_error_clear(NULL);
		k++;
	}
	actual = ft_substr(str, 0, ft_strlen(str));
	if (actual[0] != '0' && actual[1] != '\0' && ft_atoi_extended(actual) == 0)
	{
		free(actual);
		ft_error_clear(NULL);
	}
	free(actual);
}

void	check_args(int argc, char **argv)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 0)
			ft_error_clear(NULL);
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split[j])
		{
			checker_split_helper(split[j]);
			j++;
		}
		i++;
		free_split(split);
	}
}
