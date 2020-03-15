/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:00:54 by jmaynard          #+#    #+#             */
/*   Updated: 2019/07/25 16:08:15 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_move_last(t_stack **a, t_stack **b, const int mid, char **str)
{
	t_stack *last;
	int		right;

	last = ft_getn(*a, ft_stack_len(*a) - 1);
	right = 0;
	while (last->data < mid)
	{
		ft_revrot(a);
		ft_push(b, a);
		if (!(ft_stradd(str, "rra\npb\n")))
			return (-1);
		(right)++;
		last = ft_getn(*a, ft_stack_len(*a) - 1);
	}
	return (right);
}

int		ft_move_first(t_stack **a, t_stack **b, const int mid, char **str)
{
	t_stack *first;
	int		right;

	right = 0;
	first = *a;
	while (first->data < mid)
	{
		ft_push(b, a);
		if (!(ft_stradd(str, "pb\n")))
			return (-1);
		(right)++;
		first = *a;
	}
	return (right);
}

int		ft_mv_last(t_stack **b, t_stack **a, const int mid, char **str)
{
	int		right;
	t_stack	*last;

	right = 0;
	last = ft_getn(*b, ft_stack_len(*b) - 1);
	while (last->data >= mid)
	{
		ft_revrot(b);
		ft_push(a, b);
		if (!(ft_stradd(str, "rrb\npa\n")))
			return (-1);
		(right)++;
		last = ft_getn(*b, ft_stack_len(*b) - 1);
	}
	return (right);
}

int		ft_mv_first(t_stack **b, t_stack **a, const int mid, char **str)
{
	t_stack *first;
	int		right;

	first = *b;
	right = 0;
	while (first->data > mid)
	{
		ft_push(a, b);
		if (!(ft_stradd(str, "pa\n")))
			return (-1);
		(right)++;
		first = *b;
	}
	return (right);
}
