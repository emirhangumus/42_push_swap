/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 04:16:00 by egumus            #+#    #+#             */
/*   Updated: 2023/12/17 19:00:44 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
			ft_checker_error(NULL);
		k++;
	}
	actual = ft_substr(str, 0, ft_strlen(str));
	if (actual[0] != '0' && actual[1] != '\0' && ft_atoi_extended(actual) == 0)
	{
		free(actual);
		ft_checker_error(NULL);
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
			ft_checker_error(NULL);
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
