/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:19:36 by egumus            #+#    #+#             */
/*   Updated: 2023/12/16 13:20:00 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_clear(t_state *state)
{
	ft_printf("Error\n");
	if (state)
		free_state(state);
	exit(1);
}
