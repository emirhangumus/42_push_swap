/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:17:13 by egumus            #+#    #+#             */
/*   Updated: 2023/12/17 17:34:30 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct s_node
{
	int				nb;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_state
{
	t_node	*a;
	t_node	*b;
	t_node	*moves;
	int		size_a;
	int		size_b;
}					t_state;

void	apply_moves(t_state *state);
void	apply_move(t_state *state, t_node *s);
void	fill_stack_a(t_state *state, int argc, char **argv);
int		ft_get_move(char *line, int len);
void	check_args(int argc, char **argv);

void	ft_checker_error(t_state *state);
void	free_checker_state(t_state *state);
void	free_split(char **split);

t_node	*new_node(int nb);
void	add_node(t_node **head, t_node *node);

int		is_existing(t_node *head, int nb);
int		is_sorted(t_node *head);

void	ft_print_list(t_node *lst);
int		ft_atoi_extended(const char *nptr);

void	sa(t_state *state);
void	sb(t_state *state);
void	ss(t_state *state);
void	ra(t_state *state);
void	rb(t_state *state);
void	rr(t_state *state);
void	rra(t_state *state);
void	rrb(t_state *state);
void	rrr(t_state *state);
void	pa(t_state *state);
void	pb(t_state *state);

#endif